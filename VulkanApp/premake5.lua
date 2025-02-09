project "VulkanApp"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"

    targetdir "bin/%{cfg.buildcfg}"
    objdir "bin/obj/%{cfg.buildcfg}"

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "src/",
        "%{IncludeDir.glm}",
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Vulkan}",
        "%{IncludeDir.stb}",
        "%{IncludeDir.imgui}",
        "%{IncludeDir.tinyobjloader}"
    }

    libdirs {
        "%{LibraryDir.Vulkan}",
        "%{LibraryDir.GLFW}",
        "%{LibraryDir.stb}",
        "%{LibraryDir.imgui}",
        "%{LibraryDir.tinyobjloader}"
    }

    links {
        "ImGui",
        "GLFW",
        "vulkan-1",
        "stb",
        "tinyobjloader"
    }
    
    filter "configurations:Debug"
        defines "DEBUG"

        symbols "On"
        optimize "Off"
        runtime "Debug"

    filter "configurations:Release"
        defines "RELEASE"

        symbols "Off"
        optimize "On"
        runtime "Release"

    filter "configurations:Dist"
        defines "DIST"

        symbols "Off"
        optimize "On"
        runtime "Release"

    filter ""