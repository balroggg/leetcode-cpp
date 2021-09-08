cmake_minimum_required(VERSION 3.20)

project(leetcode-cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)

FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.0.0-preview3
)

FetchContent_MakeAvailable(Catch2)

add_executable(tests
    easy/0001_two_sum.cpp
    easy/0007_reverse_integer.cpp
    easy/0009_palindrome_number.cpp
    easy/0013_roman_to_integer.cpp
    easy/1979_find_gcd_of_array.cpp
)

target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)
