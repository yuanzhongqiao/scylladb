/*
 * Copyright (C) 2017-present ScyllaDB
 */

/*
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

#include "auth/standard_role_manager.hh"

#include "test/lib/scylla_test_case.hh"

#include "test/lib/cql_test_env.hh"

auto make_manager(cql_test_env& env) {
    auto stop_role_manager = [] (auth::standard_role_manager* m) {
        m->stop().get();
        std::default_delete<auth::standard_role_manager>()(m);
    };
    return std::unique_ptr<auth::standard_role_manager, decltype(stop_role_manager)>(
            new auth::standard_role_manager(env.local_qp(), env.migration_manager().local()),
            std::move(stop_role_manager));
}

SEASTAR_TEST_CASE(create_role) {
    return do_with_cql_env_thread([](auto&& env) {
        auto m = make_manager(env);
        m->start().get();

        const auto anon = auth::authenticated_user();

        //
        // Create a role, and verify its properties.
        //

        auth::role_config c;
        c.is_superuser = true;

        m->create("admin", c).get();
        BOOST_REQUIRE_EQUAL(m->exists("admin").get(), true);
        BOOST_REQUIRE_EQUAL(m->can_login("admin").get(), false);
        BOOST_REQUIRE_EQUAL(m->is_superuser("admin").get(), true);

        BOOST_REQUIRE_EQUAL(
                m->query_granted("admin", auth::recursive_role_query::yes).get(),
                std::unordered_set<sstring>{"admin"});

        //
        // Creating a role that already exists is an error.
        //

        BOOST_REQUIRE_THROW(m->create("admin", c).get(), auth::role_already_exists);
    });
}

SEASTAR_TEST_CASE(drop_role) {
    return do_with_cql_env_thread([](auto&& env) {
        auto m = make_manager(env);
        m->start().get();

        const auto anon = auth::authenticated_user();

        //
        // Create a role, then drop it, then verify it's gone.
        //

        m->create("lord", auth::role_config()).get();
        m->drop("lord").get();
        BOOST_REQUIRE_EQUAL(m->exists("lord").get(), false);

        //
        // Dropping a role revokes it from other roles and revokes other roles from it.
        //

        m->create("peasant", auth::role_config()).get();
        m->create("lord", auth::role_config()).get();
        m->create("king", auth::role_config()).get();

        auth::role_config tim_config;
        tim_config.is_superuser = false;
        tim_config.can_login = true;
        m->create("tim", tim_config).get();

        m->grant("lord", "peasant").get();
        m->grant("king", "lord").get();
        m->grant("tim", "lord").get();

        m->drop("lord").get();

        BOOST_REQUIRE_EQUAL(
                m->query_granted("tim", auth::recursive_role_query::yes).get(),
                std::unordered_set<sstring>{"tim"});

        BOOST_REQUIRE_EQUAL(
                m->query_granted("king", auth::recursive_role_query::yes).get(),
                std::unordered_set<sstring>{"king"});

        //
        // Dropping a role that does not exist is an error.
        //

        BOOST_REQUIRE_THROW(m->drop("emperor").get(), auth::nonexistant_role);
    });
}

SEASTAR_TEST_CASE(grant_role) {
    return do_with_cql_env_thread([](auto&& env) {
        auto m = make_manager(env);
        m->start().get();

        const auto anon = auth::authenticated_user();

        auth::role_config jsnow_config;
        jsnow_config.is_superuser = false;
        jsnow_config.can_login = true;
        m->create("jsnow", jsnow_config).get();

        m->create("lord", auth::role_config()).get();
        m->create("king", auth::role_config()).get();

        //
        // All kings have the rights of lords, and 'jsnow' is a king.
        //

        m->grant("king", "lord").get();
        m->grant("jsnow", "king").get();

        BOOST_REQUIRE_EQUAL(
                m->query_granted("king", auth::recursive_role_query::yes).get(),
                (std::unordered_set<sstring>{"king", "lord"}));

        BOOST_REQUIRE_EQUAL(
                m->query_granted("jsnow", auth::recursive_role_query::no).get(),
               (std::unordered_set<sstring>{"jsnow", "king"}));

        BOOST_REQUIRE_EQUAL(
                m->query_granted("jsnow", auth::recursive_role_query::yes).get(),
                (std::unordered_set<sstring>{"jsnow", "king", "lord"}));

        // A non-existing role cannot be granted.
        BOOST_REQUIRE_THROW(m->grant("jsnow", "doctor").get(), auth::nonexistant_role);

        // A role cannot be granted to a non-existing role.
        BOOST_REQUIRE_THROW(m->grant("hpotter", "lord").get(), auth::nonexistant_role);
    });
}

SEASTAR_TEST_CASE(revoke_role) {
    return do_with_cql_env_thread([](auto&& env) {
        auto m = make_manager(env);
        m->start().get();

        const auto anon = auth::authenticated_user();

        auth::role_config rrat_config;
        rrat_config.is_superuser = false;
        rrat_config.can_login = true;
        m->create("rrat", rrat_config).get();

        m->create("chef", auth::role_config()).get();
        m->create("sous_chef", auth::role_config()).get();

        m->grant("chef", "sous_chef").get();
        m->grant("rrat", "chef").get();

        m->revoke("chef", "sous_chef").get();
        BOOST_REQUIRE_EQUAL(
                m->query_granted("rrat", auth::recursive_role_query::yes).get(),
                (std::unordered_set<sstring>{"chef", "rrat"}));

        m->revoke("rrat", "chef").get();
        BOOST_REQUIRE_EQUAL(
                m->query_granted("rrat", auth::recursive_role_query::yes).get(),
                std::unordered_set<sstring>{"rrat"});

        // A non-existing role cannot be revoked.
        BOOST_REQUIRE_THROW(m->revoke("rrat", "taster").get(), auth::nonexistant_role);

        // A role cannot be revoked from a non-existing role.
        BOOST_REQUIRE_THROW(m->revoke("ccasper", "chef").get(), auth::nonexistant_role);

        // Revoking a role not granted is an error.
        BOOST_REQUIRE_THROW(m->revoke("rrat", "sous_chef").get(), auth::revoke_ungranted_role);
    });
}

SEASTAR_TEST_CASE(alter_role) {
    return do_with_cql_env_thread([](auto&& env) {
        auto m = make_manager(env);
        m->start().get();

        const auto anon = auth::authenticated_user();

        auth::role_config tsmith_config;
        tsmith_config.is_superuser = true;
        tsmith_config.can_login = true;
        m->create("tsmith", tsmith_config).get();

        auth::role_config_update u;
        u.can_login = false;

        m->alter("tsmith", u).get();

        BOOST_REQUIRE_EQUAL(m->is_superuser("tsmith").get(), true);
        BOOST_REQUIRE_EQUAL(m->can_login("tsmith").get(), false);

        // Altering a non-existing role is an error.
        BOOST_REQUIRE_THROW(m->alter("hjones", u).get(), auth::nonexistant_role);
    });
}
