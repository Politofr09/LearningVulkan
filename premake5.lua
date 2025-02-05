include "Dependencies.lua"

CheckVulkanSDK()

workspace "LearningVulkan"
    architecture "x86_64"
    configurations { "Debug", "Release", "Dist" }
    staticruntime "on"
    
    startproject "VulkanApp"
    include "VulkanApp"

    group "Dependencies"
        include "vendor/GLFW"
        include "vendor/stb"
    group ""
