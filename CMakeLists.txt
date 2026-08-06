cmake_minimum_required(VERSION 3.20)

project(cpp_all VERSION 0.1.0 LANGUAGES CXX)

include(CTest)
include(cmake/AddCppExample.cmake)
find_package(Threads REQUIRED)

option(CPP_ALL_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

add_subdirectory(examples)
add_subdirectory(templates)
