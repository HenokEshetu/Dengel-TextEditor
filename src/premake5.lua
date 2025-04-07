project "TextEditor"
    kind "ConsoleApp"
    language "C++"
    files { "**.cpp" }
    links { "core", "ui" }  -- Links with core/ui libs (like CMake's target_link_libraries)

    -- Optional: SDL2/OpenGL (commented out like in CMake)
    -- filter "system:linux"
    --     links { "SDL2", "GL" }
