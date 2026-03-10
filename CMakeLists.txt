cmake_minimum_required(VERSION 3.16)
project(command_line_utility)
set(CMAKE_CXX_STANDARD 17)

set(SOURCES
main.cpp
anagram_checker.cpp
includes/utilities.cpp
basic_calculator.cpp
temperature_converter.cpp
palindrome_checker.cpp)

set(HEADERS
includes/utilities.h)

add_executable(command_line_utility
${SOURCES}
${HEADERS})