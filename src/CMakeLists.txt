set(src
    center_monomials.cpp
    constant_series.cpp
    )


add_library(${FIGTREE_LIB_TARGET} ${src})
target_link_libraries(${FIGTREE_LIB_TARGET} ${deps})
set_property(
    TARGET ${FIGTREE_LIB_TARGET}
    PROPERTY OUTPUT_NAME ${FIGTREE_LIB_NAME}
    )
