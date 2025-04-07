workspace "dengel_text_editor"
    configurations { "Debug", "Release" }
    location "build"
    cppdialect "C++23"
    systemversion "latest"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin-int/%{cfg.buildcfg}"

    filter { "system:linux or macosx" }
        toolset "clang"

    include "lib/core"
    include "lib/ui"
    include "src"
