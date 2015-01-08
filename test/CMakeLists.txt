set(src
    center_monomials_test.cpp
    constant_series_test.cpp
    error_bound_test.cpp
    nchoosek_test.cpp
    radius_bounds_test.cpp
    truncation_test.cpp
    )

set(deps
    ${FIGTREE_LIB_TARGET}
    gtest_main
    )


include_directories(
    ${gtest_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
    )

add_executable(${FIGTREE_TEST_TARGET} ${src})
target_link_libraries(${FIGTREE_TEST_TARGET} ${deps})
