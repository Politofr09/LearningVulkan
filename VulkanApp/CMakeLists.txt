cmake_minimum_required(VERSION 3.8.0)

find_package(Vulkan REQUIRED)

include(FetchContent)

FetchContent_Declare(
    glfw
    GIT_REPOSITORY https://github.com/glfw/glfw.git
    GIT_TAG latest
)
FetchContent_MakeAvailable(glfw)

FetchContent_Declare(
    glm
    GIT_REPOSITORY https://github.com/g-truc/glm.git
    GIT_TAG master
)
FetchContent_MakeAvailable(glm)

FetchContent_Declare(stb
    stb
    GIT_REPOSITORY https://github.com/nothings/stb
    GIT_TAG master
)
FetchContent_MakeAvailable(stb)

project(VulkanApp)

add_executable(VulkanApp
    src/Main.cpp
)

target_include_directories(VulkanApp PRIVATE 
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    ${glfw_SOURCE_DIR}/include
    ${glm_SOURCE_DIR}
    ${stb_SOURCE_DIR}
)

target_link_libraries(${PROJECT_NAME} glfw Vulkan::Vulkan glm::glm)

target_compile_definitions(VulkanApp PRIVATE
    $<$<CONFIG:Debug>:DEBUG>
    $<$<CONFIG:Release>:RELEASE>
)