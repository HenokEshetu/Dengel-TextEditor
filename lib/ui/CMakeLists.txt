file(GLOB UI_SOURCES *.cpp)

add_library(ui STATIC ${UI_SOURCES})

target_include_directories(ui PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/vendor/SDL/include
)

target_link_libraries(ui PRIVATE SDL3::SDL3)
