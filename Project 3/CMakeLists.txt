cmake_minimum_required(VERSION 3.3)

project(QUICKSORT-MULTI)
add_executable(quicksort Main.cpp SerialQuicksort.h ConcurrentQuicksort.h)
set_property(TARGET quicksort PROPERTY CXX_STANDARD 11)
