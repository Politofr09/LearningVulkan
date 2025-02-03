include "Dependencies.lua"

CheckVulkanSDK()

workspace "LearningVulkan"
    architecture "x86_64"
    configurations { "Debug", "Release" }
    staticruntime "on"
    
    startproject "VulkanApp"
    include "VulkanApp"

    group "Dependencies"
        include "vendor/GLFW"
        include "vendor/stb"
    group ""

    filter "configurations:Debug"
        symbols "On"
        optimize "Off"
        runtime "Debug"

    filter "configurations:Release"
        symbols "Off"
        optimize "On"
        runtime "Release"

    filter ""