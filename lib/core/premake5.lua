project "core"
    kind "StaticLib"
    language "C++"
    files { "**.cpp" }  -- Matches CMake's file(GLOB)
    includedirs { "." } -- Public include dir (like CMake's target_include_directories)
