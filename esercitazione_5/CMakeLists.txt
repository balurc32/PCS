cmake_minimum_required(VERSION 3.20)
project(esercitazione5) 

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla -Wno-sign-compare")

set(SRC_rf esempio_randfiller.cpp)
add_executable(esempio_randfiller ${SRC_rf})

set(SRC_tc esempio_timecounter.cpp timecounter.cpp)
add_executable(esempio_timecounter ${SRC_tc})

set(SRC_test_sorts timecounter.cpp measure_sorts.cpp)
add_executable(measure_sorts ${SRC_test_sorts})

enable_testing()

add_executable(test_bubblesort test_bubblesort.cpp)
add_test(NAME bubblesort COMMAND test_bubblesort)

add_executable(test_insertionsort test_insertionsort.cpp)
add_test(NAME insertionsort COMMAND test_insertionsort)

add_executable(test_selectionsort test_selectionsort.cpp)
add_test(NAME selectionsort COMMAND test_selectionsort)

add_executable(test_strings test_strings.cpp)
add_test(NAME strings COMMAND test_strings)

add_executable(test_mergesort_strings test_mergesort_strings.cpp)
add_test(NAME mergesort_strings COMMAND test_mergesort_strings)

add_executable(test_quicksort_strings test_quicksort_strings.cpp)
add_test(NAME quicksort_strings COMMAND test_quicksort_strings)

add_executable(test_mergesort test_mergesort.cpp)
add_test(NAME mergesort COMMAND test_mergesort)

add_executable(test_quicksort test_quicksort.cpp)
add_test(NAME quicksort COMMAND test_quicksort)

