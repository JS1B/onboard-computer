add_library(vector3_library STATIC
    vector3.cpp
)

target_include_directories(vector3_library PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(vector3_library PUBLIC
    pico_stdlib
)
