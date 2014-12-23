include_directories(${PROJECT_SOURCE_DIR}/include)

set(src
    test.cpp
    )

set(deps
    ${FIGTREE_TARGET_LIB}
    )


add_executable(${FIGTREE_TARGET_TEST} ${src})
target_link_libraries(${FIGTREE_TARGET_TEST} ${deps})

install(TARGETS ${FIGTREE_TARGET_TEST}
    RUNTIME DESTINATION bin
    )
