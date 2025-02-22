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
        "%{IncludeDir.imgui}",
        "%{IncludeDir.tinyobjloader}",
        "%{IncludeDir.tinygltf}"
    }

    libdirs {
        "%{LibraryDir.Vulkan}",
        "%{LibraryDir.GLFW}",
        "%{LibraryDir.imgui}",
        "%{LibraryDir.tinyobjloader}",
        "%{LibraryDir.tinygltf}"
    }

    links {
        "ImGui",
        "GLFW",
        "vulkan-1",
        "tinygltf"
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