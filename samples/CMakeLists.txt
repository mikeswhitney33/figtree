include_directories(${PROJECT_SOURCE_DIR}/include)

set(src
    sample.cpp
    )

add_executable(${FIGTREE_TARGET_SAMPLE} ${src})
target_link_libraries(${FIGTREE_TARGET_SAMPLE} ${FIGTREE_TARGET_LIB})
