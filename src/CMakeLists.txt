file(GLOB SRC_FILES *.cpp)
add_executable(TextEditor ${SRC_FILES})

# Find SDL2
# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS})

# Find OpenGL
# find_package(OpenGL REQUIRED)
# include_directories(${OPENGL_INCLUDE_DIRS})

# Link everything
target_link_libraries(TextEditor
    core
    ui
    # ${SDL2_LIBRARIES}
    # ${OPENGL_LIBRARIES}
)
