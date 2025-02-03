project "stb"
    kind "StaticLib"
    language "C"

	targetdir "bin/%{cfg.buildcfg}"
	objdir "bin-obj/%{cfg.buildcfg}"

    files { "src/**.c", "src/**.h" }

    filter "configurations:Debug"
        symbols "On"
        optimize "Off"
        runtime "Debug"

    filter "configurations:Release"
        symbols "Off"
        optimize "On"
        runtime "Release"