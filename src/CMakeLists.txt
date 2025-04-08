file(GLOB SRC_FILES *.cpp)
add_executable(TextEditor ${SRC_FILES})

# Link all dependencies using consistent PRIVATE keyword syntax
target_link_libraries(TextEditor PRIVATE
    core
    ui
)

# Optional OpenGL support (uncomment if needed)
# find_package(OpenGL REQUIRED)
# target_link_libraries(TextEditor PRIVATE OpenGL::GL)
