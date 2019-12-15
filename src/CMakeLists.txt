###########################################################################
#  Test Driver for Parallel Merge Sort                                    #
#  Created by Malith Jayaweera on 1/11/19.                                #
#  Published at malithjayaweera.com for public use.                       #
#  Copyright © 2019 Malith Jayaweera. All rights reserved.                # 
#                                                                         #
#                                                                         #
# This program is free software: you can redistribute it and/or modify    #
# it under the terms of the GNU General Public License as published by    #
# the Free Software Foundation, either version 3 of the License, or       #
# (at your option) any later version.                                     #
#                                                                         #
# This program is distributed in the hope that it will be useful,         #
# but WITHOUT ANY WARRANTY; without even the implied warranty of          #
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the           #
# GNU General Public License for more details.                            #
#                                                                         #
# You should have received a copy of the GNU General Public License       #
# along with this program.  If not, see <http://www.gnu.org/licenses/>.   #
###########################################################################

cmake_minimum_required(VERSION 3.15.1)   # CMake version check
project(mergeSort VERSION 0.0.1)       # Create project

include(CTest)
include(GoogleTest)
include(ExternalProject)
set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

ExternalProject_Add(googletest_
    GIT_REPOSITORY https://github.com/google/googletest
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
    GIT_TAG release-1.8.1
)

include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
link_directories(${EXTERNAL_INSTALL_LOCATION}/lib)

# Add executable target with source files listed in SOURCE_FILES variable
add_executable(main)

target_sources(main
    PUBLIC
        ${CMAKE_CURRENT_LIST_DIR}/parallel_merge_sort.cc
        ${CMAKE_CURRENT_LIST_DIR}/../test/main.cc
)

add_dependencies(main googletest_)
target_link_libraries(main gtest gtest_main pthread)