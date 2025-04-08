workspace "dengel_text_editor"
    configurations { "Debug", "Release" }
    location "build"
    cppdialect "C++23"
    systemversion "latest"

    targetdir "bin/%{prj.name}"
    objdir "bin-int/%{prj.name}"

    filter { "system:linux or macosx" }
        toolset "clang"

    include "lib/core"
    include "lib/ui"
    include "src"
