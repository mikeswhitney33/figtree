set(src
    nchoosek_test.cpp
    )

set(deps
    gtest_main
    )


include_directories(
    ${gtest_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    )

add_executable(${FIGTREE_TEST_TARGET} ${src})
target_link_libraries(${FIGTREE_TEST_TARGET} ${deps})
