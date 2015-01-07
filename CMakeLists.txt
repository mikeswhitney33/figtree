# Setup
cmake_minimum_required(VERSION 2.8.7 FATAL_ERROR)
project(figtree CXX)

set(CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake" ${CMAKE_MODULE_PATH})
set(CMAKE_MACOSX_RPATH ON)


# Options
option(BUILD_SHARED_LIBS "Build all libraries as shared" ON)
option(BUILD_TESTS "Build tests" ON)


# Configuration
set(CMAKE_CXX_FLAGS "-std=c++11" ${CMAKE_CXX_FLAGS})


# Targts
set(FIGTREE_LIB_TARGET figtree-lib)
set(FIGTREE_LIB_NAME figtree)
set(FIGTREE_TEST_TARGET figtree-test)


# Output paths
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/lib)


# Requirements
find_package(Flann REQUIRED)


# Subdirectories
add_subdirectory(include)
add_subdirectory(src)

if (BUILD_TESTS)
    add_subdirectory(vendor/gtest-1.7.0)
    add_subdirectory(test)
endif (BUILD_TESTS)
