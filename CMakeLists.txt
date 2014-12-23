#
# Setup
#
cmake_minimum_required(VERSION 2.8.7)
project(figtree)
set(CMAKE_MACOSX_RPATH ON)


#
# Options
#
option(BUILD_SHARED_LIBS "Create shared libraries" ON)
option(WITH_ANN "Build figree with ANN support" ON)
option(WITH_SAMPLES "Build figtree with samples" OFF)
option(WITH_TESTS "Build figtree with tests" OFF)


#
# Targets
#
set(FIGTREE_TARGET_LIB figtree)
set(FIGTREE_TARGET_TEST figtree-test)
set(FIGTREE_TARGET_SAMPLE figtree-sample)
set(ANN_TARGET_LIB ann_figtree_version)


#
# Subdirectories
#
if (WITH_ANN)
    add_subdirectory(external)
    include_directories("${CMAKE_SOURCE_DIR}/external/ann_1.1.1/include")
else (WITH_ANN)
    add_definitions(-DFIGTREE_NO_ANN)
endif (WITH_ANN)

add_subdirectory(include)
add_subdirectory(src)

if (WITH_SAMPLES)
    add_subdirectory(samples)
endif (WITH_SAMPLES)

if (WITH_TESTS)
    add_subdirectory(test)
endif (WITH_TESTS)
