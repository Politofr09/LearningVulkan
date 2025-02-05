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
IncludeDir["stb"] = "%{wks.location}/vendor/stb/src/"
IncludeDir["imgui"] = "%{wks.location}/vendor/imgui/"

LibraryDir = {}
LibraryDir["Vulkan"] = "%{VULKAN_SDK}/Lib/"
LibraryDir["GLFW"] = "%{wks.location}/vendor/GLFW/bin/%{cfg.buildcfg}/"
LibraryDir["stb"] = "%{wks.location}/vendor/stb/bin/%{cfg.buildcfg}/"
LibraryDir["imgui"] = "%{wks.location}/vendor/imgui/bin/%{cfg.buildcfg}/"