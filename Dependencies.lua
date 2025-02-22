-- Check if VULKAN is installed
VULKAN_SDK = nil

function CheckVulkanSDK()
    if not os.getenv("VULKAN_SDK") then
        error("VULKAN_SDK environment variable is not set. Please install Vulkan SDK and set the VULKAN_SDK environment variable.")
    end

    print("Vulkan SDK found!")
    print("Using the following Vulkan installation: " .. os.getenv("VULKAN_SDK"))
    VULKAN_SDK = os.getenv("VULKAN_SDK")
end

IncludeDir = {}
IncludeDir["Vulkan"] = "%{VULKAN_SDK}/Include/"
IncludeDir["glm"] = "%{wks.location}/vendor/glm/"
IncludeDir["GLFW"] = "%{wks.location}/vendor/GLFW/include/"
IncludeDir["imgui"] = "%{wks.location}/vendor/imgui/"
IncludeDir["tinygltf"] = "%{wks.location}/vendor/"

LibraryDir = {}
LibraryDir["Vulkan"] = "%{VULKAN_SDK}/Lib/"
LibraryDir["GLFW"] = "%{wks.location}/vendor/GLFW/bin/%{cfg.buildcfg}/"
LibraryDir["imgui"] = "%{wks.location}/vendor/imgui/bin/%{cfg.buildcfg}/"
LibraryDir["tinygltf"] = "%{wks.location}/vendor/tinygltf/bin/%{cfg.buildcfg}/"

function IncludeDependencyProjects()
    include "vendor/GLFW"
    include "vendor/imgui"

    -- tinygltf comes with stb_image included
    -- we just use stb from tinygltf
    include "vendor/tinygltf"
end