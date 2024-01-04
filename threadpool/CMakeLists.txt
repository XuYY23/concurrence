cmake_minimum_required(VERSION 2.8)

project(threadpool CXX)

if(NOT CMAKE_BUILD_TYPE)
   set(CMAKE_BUILD_TYPE "Debug")
endif()

add_compile_options(-pthread -g -w -std=c++17)

add_subdirectory(examples bin)