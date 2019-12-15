/*
 *  Parallel Merge Sort
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
#pragma once

/* function definitions */
int parallel_merge_sort(int * array, int length, int num_threads);
int generate_random_number(unsigned int lower_limit, unsigned int upper_limit);
void merge_sort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);
void* thread_merge_sort(void* arg);
void merge_sections_of_array(int arr[], int number, int aggregation);
void test_array_is_in_order(int arr[]);