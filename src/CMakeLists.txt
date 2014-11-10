include_directories(${PROJECT_SOURCE_DIR}/include)

set(src
    figtree.cpp
    KCenterClustering.cpp
    )


add_library(${FIGTREE_TARGET_LIB} ${src})
if (WITH_ANN)
    target_link_libraries(${FIGTREE_TARGET_LIB} ${ANN_TARGET_LIB})
endif (WITH_ANN)

install(TARGETS ${FIGTREE_TARGET_LIB}
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    )
