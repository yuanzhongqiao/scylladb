
/*
 * Copyright (C) 2017-present ScyllaDB
 */

/*
 * SPDX-License-Identifier: AGPL-3.0-or-later
 */

/*
 * This file was autogenerated by gen_segmented_compress_params.py.
 */

#include "compress.hh"

#include <array>

namespace sstables {

const uint64_t bucket_size{4096};

struct bucket_info {
    uint64_t chunk_size_log2;
    uint64_t best_data_size_log2;
    uint64_t segments_per_bucket;
};

// The largest data chunk from the file a bucketful of offsets can
// cover, precalculated for different chunk sizes, plus the number
// of segments that are needed to address the whole area.
const std::array<bucket_info, 27> bucket_infos{{
    {4, 16, 817 /*out of the max of 1024*/},
    {5, 17, 527 /*out of the max of 683*/},
    {6, 18, 605 /*out of the max of 820*/},
    {7, 19, 474 /*out of the max of 683*/},
    {8, 20, 380 /*out of the max of 586*/},
    {9, 21, 311 /*out of the max of 512*/},
    {10, 22, 289 /*out of the max of 512*/},
    {11, 23, 270 /*out of the max of 512*/},
    {12, 23, 255 /*out of the max of 256*/},
    {13, 24, 240 /*out of the max of 256*/},
    {14, 25, 227 /*out of the max of 256*/},
    {15, 26, 215 /*out of the max of 256*/},
    {16, 27, 204 /*out of the max of 256*/},
    {17, 28, 194 /*out of the max of 256*/},
    {18, 29, 185 /*out of the max of 256*/},
    {19, 30, 177 /*out of the max of 256*/},
    {20, 31, 170 /*out of the max of 256*/},
    {21, 32, 163 /*out of the max of 256*/},
    {22, 33, 157 /*out of the max of 256*/},
    {23, 34, 151 /*out of the max of 256*/},
    {24, 35, 146 /*out of the max of 256*/},
    {25, 36, 141 /*out of the max of 256*/},
    {26, 37, 136 /*out of the max of 256*/},
    {27, 38, 131 /*out of the max of 256*/},
    {28, 38, 128 /*out of the max of 128*/},
    {29, 39, 124 /*out of the max of 128*/},
    {30, 40, 120 /*out of the max of 128*/}}};

struct segment_info {
    uint8_t data_size_log2;
    uint8_t chunk_size_log2;
    uint8_t grouped_offsets;
};

// Precomputed optimal segment information for different data and chunk sizes.
const std::array<segment_info, 675> segment_infos{{
    {16, 4, 4},
    {16, 5, 6},
    {16, 6, 5},
    {16, 7, 6},
    {16, 8, 4},
    {16, 9, 4},
    {16, 10, 4},
    {16, 11, 4},
    {16, 12, 2},
    {16, 13, 2},
    {16, 14, 2},
    {16, 15, 1},
    {16, 16, 1},
    {16, 17, 1},
    {16, 18, 1},
    {16, 19, 1},
    {16, 20, 1},
    {16, 21, 1},
    {16, 22, 1},
    {16, 23, 1},
    {16, 24, 1},
    {16, 25, 1},
    {16, 26, 1},
    {16, 27, 1},
    {16, 28, 1},
    {16, 29, 1},
    {16, 30, 1},
    {17, 4, 7},
    {17, 5, 6},
    {17, 6, 5},
    {17, 7, 6},
    {17, 8, 4},
    {17, 9, 4},
    {17, 10, 4},
    {17, 11, 4},
    {17, 12, 4},
    {17, 13, 2},
    {17, 14, 2},
    {17, 15, 2},
    {17, 16, 1},
    {17, 17, 1},
    {17, 18, 1},
    {17, 19, 1},
    {17, 20, 1},
    {17, 21, 1},
    {17, 22, 1},
    {17, 23, 1},
    {17, 24, 1},
    {17, 25, 1},
    {17, 26, 1},
    {17, 27, 1},
    {17, 28, 1},
    {17, 29, 1},
    {17, 30, 1},
    {18, 4, 7},
    {18, 5, 6},
    {18, 6, 5},
    {18, 7, 6},
    {18, 8, 4},
    {18, 9, 4},
    {18, 10, 4},
    {18, 11, 4},
    {18, 12, 4},
    {18, 13, 4},
    {18, 14, 2},
    {18, 15, 2},
    {18, 16, 2},
    {18, 17, 1},
    {18, 18, 1},
    {18, 19, 1},
    {18, 20, 1},
    {18, 21, 1},
    {18, 22, 1},
    {18, 23, 1},
    {18, 24, 1},
    {18, 25, 1},
    {18, 26, 1},
    {18, 27, 1},
    {18, 28, 1},
    {18, 29, 1},
    {18, 30, 1},
    {19, 4, 7},
    {19, 5, 6},
    {19, 6, 5},
    {19, 7, 6},
    {19, 8, 7},
    {19, 9, 8},
    {19, 10, 4},
    {19, 11, 4},
    {19, 12, 4},
    {19, 13, 4},
    {19, 14, 4},
    {19, 15, 2},
    {19, 16, 2},
    {19, 17, 2},
    {19, 18, 1},
    {19, 19, 1},
    {19, 20, 1},
    {19, 21, 1},
    {19, 22, 1},
    {19, 23, 1},
    {19, 24, 1},
    {19, 25, 1},
    {19, 26, 1},
    {19, 27, 1},
    {19, 28, 1},
    {19, 29, 1},
    {19, 30, 1},
    {20, 4, 7},
    {20, 5, 6},
    {20, 6, 9},
    {20, 7, 6},
    {20, 8, 7},
    {20, 9, 8},
    {20, 10, 8},
    {20, 11, 4},
    {20, 12, 4},
    {20, 13, 4},
    {20, 14, 4},
    {20, 15, 4},
    {20, 16, 2},
    {20, 17, 2},
    {20, 18, 2},
    {20, 19, 1},
    {20, 20, 1},
    {20, 21, 1},
    {20, 22, 1},
    {20, 23, 1},
    {20, 24, 1},
    {20, 25, 1},
    {20, 26, 1},
    {20, 27, 1},
    {20, 28, 1},
    {20, 29, 1},
    {20, 30, 1},
    {21, 4, 7},
    {21, 5, 6},
    {21, 6, 9},
    {21, 7, 6},
    {21, 8, 7},
    {21, 9, 8},
    {21, 10, 8},
    {21, 11, 8},
    {21, 12, 4},
    {21, 13, 4},
    {21, 14, 4},
    {21, 15, 4},
    {21, 16, 4},
    {21, 17, 2},
    {21, 18, 2},
    {21, 19, 2},
    {21, 20, 1},
    {21, 21, 1},
    {21, 22, 1},
    {21, 23, 1},
    {21, 24, 1},
    {21, 25, 1},
    {21, 26, 1},
    {21, 27, 1},
    {21, 28, 1},
    {21, 29, 1},
    {21, 30, 1},
    {22, 4, 7},
    {22, 5, 11},
    {22, 6, 9},
    {22, 7, 11},
    {22, 8, 7},
    {22, 9, 8},
    {22, 10, 8},
    {22, 11, 8},
    {22, 12, 8},
    {22, 13, 4},
    {22, 14, 4},
    {22, 15, 4},
    {22, 16, 4},
    {22, 17, 4},
    {22, 18, 2},
    {22, 19, 2},
    {22, 20, 2},
    {22, 21, 1},
    {22, 22, 1},
    {22, 23, 1},
    {22, 24, 1},
    {22, 25, 1},
    {22, 26, 1},
    {22, 27, 1},
    {22, 28, 1},
    {22, 29, 1},
    {22, 30, 1},
    {23, 4, 13},
    {23, 5, 11},
    {23, 6, 9},
    {23, 7, 11},
    {23, 8, 7},
    {23, 9, 8},
    {23, 10, 8},
    {23, 11, 8},
    {23, 12, 8},
    {23, 13, 8},
    {23, 14, 4},
    {23, 15, 4},
    {23, 16, 4},
    {23, 17, 4},
    {23, 18, 4},
    {23, 19, 2},
    {23, 20, 2},
    {23, 21, 2},
    {23, 22, 1},
    {23, 23, 1},
    {23, 24, 1},
    {23, 25, 1},
    {23, 26, 1},
    {23, 27, 1},
    {23, 28, 1},
    {23, 29, 1},
    {23, 30, 1},
    {24, 4, 13},
    {24, 5, 11},
    {24, 6, 9},
    {24, 7, 11},
    {24, 8, 7},
    {24, 9, 8},
    {24, 10, 8},
    {24, 11, 8},
    {24, 12, 8},
    {24, 13, 8},
    {24, 14, 8},
    {24, 15, 4},
    {24, 16, 4},
    {24, 17, 4},
    {24, 18, 4},
    {24, 19, 4},
    {24, 20, 2},
    {24, 21, 2},
    {24, 22, 2},
    {24, 23, 1},
    {24, 24, 1},
    {24, 25, 1},
    {24, 26, 1},
    {24, 27, 1},
    {24, 28, 1},
    {24, 29, 1},
    {24, 30, 1},
    {25, 4, 13},
    {25, 5, 11},
    {25, 6, 9},
    {25, 7, 11},
    {25, 8, 7},
    {25, 9, 8},
    {25, 10, 8},
    {25, 11, 8},
    {25, 12, 8},
    {25, 13, 8},
    {25, 14, 8},
    {25, 15, 8},
    {25, 16, 4},
    {25, 17, 4},
    {25, 18, 4},
    {25, 19, 4},
    {25, 20, 4},
    {25, 21, 2},
    {25, 22, 2},
    {25, 23, 2},
    {25, 24, 1},
    {25, 25, 1},
    {25, 26, 1},
    {25, 27, 1},
    {25, 28, 1},
    {25, 29, 1},
    {25, 30, 1},
    {26, 4, 13},
    {26, 5, 11},
    {26, 6, 9},
    {26, 7, 11},
    {26, 8, 13},
    {26, 9, 8},
    {26, 10, 8},
    {26, 11, 8},
    {26, 12, 8},
    {26, 13, 8},
    {26, 14, 8},
    {26, 15, 8},
    {26, 16, 8},
    {26, 17, 4},
    {26, 18, 4},
    {26, 19, 4},
    {26, 20, 4},
    {26, 21, 4},
    {26, 22, 2},
    {26, 23, 2},
    {26, 24, 2},
    {26, 25, 1},
    {26, 26, 1},
    {26, 27, 1},
    {26, 28, 1},
    {26, 29, 1},
    {26, 30, 1},
    {27, 4, 13},
    {27, 5, 11},
    {27, 6, 9},
    {27, 7, 11},
    {27, 8, 13},
    {27, 9, 8},
    {27, 10, 8},
    {27, 11, 8},
    {27, 12, 8},
    {27, 13, 8},
    {27, 14, 8},
    {27, 15, 8},
    {27, 16, 8},
    {27, 17, 8},
    {27, 18, 4},
    {27, 19, 4},
    {27, 20, 4},
    {27, 21, 4},
    {27, 22, 4},
    {27, 23, 2},
    {27, 24, 2},
    {27, 25, 2},
    {27, 26, 1},
    {27, 27, 1},
    {27, 28, 1},
    {27, 29, 1},
    {27, 30, 1},
    {28, 4, 13},
    {28, 5, 11},
    {28, 6, 9},
    {28, 7, 11},
    {28, 8, 13},
    {28, 9, 8},
    {28, 10, 8},
    {28, 11, 8},
    {28, 12, 8},
    {28, 13, 8},
    {28, 14, 8},
    {28, 15, 8},
    {28, 16, 8},
    {28, 17, 8},
    {28, 18, 8},
    {28, 19, 4},
    {28, 20, 4},
    {28, 21, 4},
    {28, 22, 4},
    {28, 23, 4},
    {28, 24, 2},
    {28, 25, 2},
    {28, 26, 2},
    {28, 27, 1},
    {28, 28, 1},
    {28, 29, 1},
    {28, 30, 1},
    {29, 4, 13},
    {29, 5, 11},
    {29, 6, 17},
    {29, 7, 11},
    {29, 8, 13},
    {29, 9, 15},
    {29, 10, 16},
    {29, 11, 8},
    {29, 12, 8},
    {29, 13, 8},
    {29, 14, 8},
    {29, 15, 8},
    {29, 16, 8},
    {29, 17, 8},
    {29, 18, 8},
    {29, 19, 8},
    {29, 20, 4},
    {29, 21, 4},
    {29, 22, 4},
    {29, 23, 4},
    {29, 24, 4},
    {29, 25, 2},
    {29, 26, 2},
    {29, 27, 2},
    {29, 28, 1},
    {29, 29, 1},
    {29, 30, 1},
    {30, 4, 13},
    {30, 5, 11},
    {30, 6, 17},
    {30, 7, 11},
    {30, 8, 13},
    {30, 9, 15},
    {30, 10, 16},
    {30, 11, 16},
    {30, 12, 8},
    {30, 13, 8},
    {30, 14, 8},
    {30, 15, 8},
    {30, 16, 8},
    {30, 17, 8},
    {30, 18, 8},
    {30, 19, 8},
    {30, 20, 8},
    {30, 21, 4},
    {30, 22, 4},
    {30, 23, 4},
    {30, 24, 4},
    {30, 25, 4},
    {30, 26, 2},
    {30, 27, 2},
    {30, 28, 2},
    {30, 29, 1},
    {30, 30, 1},
    {31, 4, 13},
    {31, 5, 11},
    {31, 6, 17},
    {31, 7, 11},
    {31, 8, 13},
    {31, 9, 15},
    {31, 10, 16},
    {31, 11, 16},
    {31, 12, 16},
    {31, 13, 8},
    {31, 14, 8},
    {31, 15, 8},
    {31, 16, 8},
    {31, 17, 8},
    {31, 18, 8},
    {31, 19, 8},
    {31, 20, 8},
    {31, 21, 8},
    {31, 22, 4},
    {31, 23, 4},
    {31, 24, 4},
    {31, 25, 4},
    {31, 26, 4},
    {31, 27, 2},
    {31, 28, 2},
    {31, 29, 2},
    {31, 30, 1},
    {32, 4, 13},
    {32, 5, 22},
    {32, 6, 17},
    {32, 7, 11},
    {32, 8, 13},
    {32, 9, 15},
    {32, 10, 16},
    {32, 11, 16},
    {32, 12, 16},
    {32, 13, 16},
    {32, 14, 8},
    {32, 15, 8},
    {32, 16, 8},
    {32, 17, 8},
    {32, 18, 8},
    {32, 19, 8},
    {32, 20, 8},
    {32, 21, 8},
    {32, 22, 8},
    {32, 23, 4},
    {32, 24, 4},
    {32, 25, 4},
    {32, 26, 4},
    {32, 27, 4},
    {32, 28, 2},
    {32, 29, 2},
    {32, 30, 2},
    {33, 4, 13},
    {33, 5, 22},
    {33, 6, 17},
    {33, 7, 22},
    {33, 8, 13},
    {33, 9, 15},
    {33, 10, 16},
    {33, 11, 16},
    {33, 12, 16},
    {33, 13, 16},
    {33, 14, 16},
    {33, 15, 8},
    {33, 16, 8},
    {33, 17, 8},
    {33, 18, 8},
    {33, 19, 8},
    {33, 20, 8},
    {33, 21, 8},
    {33, 22, 8},
    {33, 23, 8},
    {33, 24, 4},
    {33, 25, 4},
    {33, 26, 4},
    {33, 27, 4},
    {33, 28, 4},
    {33, 29, 2},
    {33, 30, 2},
    {34, 4, 13},
    {34, 5, 22},
    {34, 6, 17},
    {34, 7, 22},
    {34, 8, 13},
    {34, 9, 15},
    {34, 10, 16},
    {34, 11, 16},
    {34, 12, 16},
    {34, 13, 16},
    {34, 14, 16},
    {34, 15, 16},
    {34, 16, 8},
    {34, 17, 8},
    {34, 18, 8},
    {34, 19, 8},
    {34, 20, 8},
    {34, 21, 8},
    {34, 22, 8},
    {34, 23, 8},
    {34, 24, 8},
    {34, 25, 4},
    {34, 26, 4},
    {34, 27, 4},
    {34, 28, 4},
    {34, 29, 4},
    {34, 30, 2},
    {35, 4, 13},
    {35, 5, 22},
    {35, 6, 17},
    {35, 7, 22},
    {35, 8, 13},
    {35, 9, 15},
    {35, 10, 16},
    {35, 11, 16},
    {35, 12, 16},
    {35, 13, 16},
    {35, 14, 16},
    {35, 15, 16},
    {35, 16, 16},
    {35, 17, 8},
    {35, 18, 8},
    {35, 19, 8},
    {35, 20, 8},
    {35, 21, 8},
    {35, 22, 8},
    {35, 23, 8},
    {35, 24, 8},
    {35, 25, 8},
    {35, 26, 4},
    {35, 27, 4},
    {35, 28, 4},
    {35, 29, 4},
    {35, 30, 4},
    {36, 4, 26},
    {36, 5, 22},
    {36, 6, 17},
    {36, 7, 22},
    {36, 8, 13},
    {36, 9, 15},
    {36, 10, 16},
    {36, 11, 16},
    {36, 12, 16},
    {36, 13, 16},
    {36, 14, 16},
    {36, 15, 16},
    {36, 16, 16},
    {36, 17, 16},
    {36, 18, 8},
    {36, 19, 8},
    {36, 20, 8},
    {36, 21, 8},
    {36, 22, 8},
    {36, 23, 8},
    {36, 24, 8},
    {36, 25, 8},
    {36, 26, 8},
    {36, 27, 4},
    {36, 28, 4},
    {36, 29, 4},
    {36, 30, 4},
    {37, 4, 26},
    {37, 5, 22},
    {37, 6, 17},
    {37, 7, 22},
    {37, 8, 13},
    {37, 9, 15},
    {37, 10, 16},
    {37, 11, 16},
    {37, 12, 16},
    {37, 13, 16},
    {37, 14, 16},
    {37, 15, 16},
    {37, 16, 16},
    {37, 17, 16},
    {37, 18, 16},
    {37, 19, 8},
    {37, 20, 8},
    {37, 21, 8},
    {37, 22, 8},
    {37, 23, 8},
    {37, 24, 8},
    {37, 25, 8},
    {37, 26, 8},
    {37, 27, 8},
    {37, 28, 4},
    {37, 29, 4},
    {37, 30, 4},
    {38, 4, 26},
    {38, 5, 22},
    {38, 6, 17},
    {38, 7, 22},
    {38, 8, 26},
    {38, 9, 15},
    {38, 10, 16},
    {38, 11, 16},
    {38, 12, 16},
    {38, 13, 16},
    {38, 14, 16},
    {38, 15, 16},
    {38, 16, 16},
    {38, 17, 16},
    {38, 18, 16},
    {38, 19, 16},
    {38, 20, 8},
    {38, 21, 8},
    {38, 22, 8},
    {38, 23, 8},
    {38, 24, 8},
    {38, 25, 8},
    {38, 26, 8},
    {38, 27, 8},
    {38, 28, 8},
    {38, 29, 4},
    {38, 30, 4},
    {39, 4, 26},
    {39, 5, 22},
    {39, 6, 17},
    {39, 7, 22},
    {39, 8, 26},
    {39, 9, 15},
    {39, 10, 16},
    {39, 11, 16},
    {39, 12, 16},
    {39, 13, 16},
    {39, 14, 16},
    {39, 15, 16},
    {39, 16, 16},
    {39, 17, 16},
    {39, 18, 16},
    {39, 19, 16},
    {39, 20, 16},
    {39, 21, 8},
    {39, 22, 8},
    {39, 23, 8},
    {39, 24, 8},
    {39, 25, 8},
    {39, 26, 8},
    {39, 27, 8},
    {39, 28, 8},
    {39, 29, 8},
    {39, 30, 4},
    {40, 4, 26},
    {40, 5, 22},
    {40, 6, 17},
    {40, 7, 22},
    {40, 8, 26},
    {40, 9, 15},
    {40, 10, 16},
    {40, 11, 16},
    {40, 12, 16},
    {40, 13, 16},
    {40, 14, 16},
    {40, 15, 16},
    {40, 16, 16},
    {40, 17, 16},
    {40, 18, 16},
    {40, 19, 16},
    {40, 20, 16},
    {40, 21, 16},
    {40, 22, 8},
    {40, 23, 8},
    {40, 24, 8},
    {40, 25, 8},
    {40, 26, 8},
    {40, 27, 8},
    {40, 28, 8},
    {40, 29, 8},
    {40, 30, 8}}};

} // namespace sstables
