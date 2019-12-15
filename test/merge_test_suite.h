/*
 *  Test Suite for Parallel Merge Sort
 *  Created by Malith Jayaweera on 1/11/19.
 *  Published at malithjayaweera.com for public use.
 *  Copyright © 2019 Malith Jayaweera. All rights reserved.
 *
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <algorithm>
#include "../src/parallel_merge_sort.h"

#define SEED 50

/*  Test to check whether sort is performed properly with varying  *
 *  input sizes but with fixed parallelism                         */
TEST(PARALLEL_MERGE_SORT, INPUT_SIZE) {
    srand(SEED);
    int length = 10000;
    int num_threads = 2;
    unsigned int lower_lim = 1;
    unsigned int upper_lim = 10000;

    /* change input sizes and test sort */
    for (int j = 10; j < 1000; j ++) {
        length = j;
        /* define array */
        int * test_arr = (int *)malloc(sizeof(int) * length);
        int * actual_arr = (int *)malloc(sizeof(int) * length);

        /* initialize array with random numbers */
        for (int i = 0; i < length; i ++) {
            int random = generate_random_number(lower_lim, upper_lim);
            test_arr[i] = random;
            actual_arr[i] = random;
        }

        /* sort */
        parallel_merge_sort(test_arr, length, num_threads);
        std::sort(actual_arr, actual_arr + length); 

        /* perform comparison */
        for (int i = 0; i < length; i ++) {
            EXPECT_EQ(test_arr[i], actual_arr[i]);
        }
        free(test_arr);
        free(actual_arr);
    }
}


/*  Test to check whether sort is performed properly with varying  *
 *  input sizes but with fixed parallelism                         */
TEST(PARALLEL_MERGE_SORT, NUM_THREADS) {
    srand(SEED);
    int length = 10000;
    int num_threads = 2;
    unsigned int lower_lim = 1;
    unsigned int upper_lim = 10000;

    /* change input sizes and test sort */
    for (int j = 1; j < 5; j ++) {
        num_threads = j;
        /* define array */
        int * test_arr = (int *)malloc(sizeof(int) * length);
        int * actual_arr = (int *)malloc(sizeof(int) * length);

        /* initialize array with random numbers */
        for (int i = 0; i < length; i ++) {
            int random = generate_random_number(lower_lim, upper_lim);
            test_arr[i] = random;
            actual_arr[i] = random;
        }

        /* sort */
        parallel_merge_sort(test_arr, length, num_threads);
        std::sort(actual_arr, actual_arr + length); 

        /* perform comparison */
        for (int i = 0; i < length; i ++) {
            EXPECT_EQ(test_arr[i], actual_arr[i]);
        }
        free(test_arr);
        free(actual_arr);
    }
}