cmake_minimum_required(VERSION 3.18)
project(MedianOfMedians)

set(CMAKE_CXX_STANDARD 14)

find_package(Catch2 REQUIRED)
add_executable(unittest unit_tests.cpp median.cpp median.hpp)
target_link_libraries(unittest PRIVATE Catch2::Catch2)