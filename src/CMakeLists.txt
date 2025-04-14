file(GLOB SRC_FILES *.cpp)

add_executable(TextEditor ${SRC_FILES})

target_link_libraries(TextEditor PRIVATE
    core
    ui
)
