# LearningVulkan
My progress learning the vulkan graphics API. Let's see how far I develop the renderer!

## Project Description

This project documents my journey learning the Vulkan graphics API. It includes various stages of development, from setting up the initial environment to creating a fully functional renderer.

## Features

- Initial setup and configuration
- Basic rendering pipeline
- Shader compilation and management
- Texture loading and mapping

## Getting Started

To get started with this project, clone the repository with the `--recursive` flag and follow the instructions in the build guide. Make sure you have the necessary dependencies installed:
```bash
git clone https://github.com/Politofr09/LearningVulkan --recursive
```

## Dependencies

- Vulkan SDK
- Premake (bundled & prebuilt)
- GLFW (submodule)
- GLM (bundled)
- stb_image (bundled)

## Build instructions

### Windows Visual studio 2022
Navigate to the `scripts` directory located at the root of the repository.
Run `Win-Setup.bat` from that directory.
Then a `.sln` file should have been generated, and you can open it.

### Linux (not tested)
Navigate to the `scripts` directory located at the root of the repository.
Run `Linux-Setup.sh` from that directory. (Make sure you `chmod +x` it...)
Makefile should have been generated!

## License

This project is licensed under the MIT License.
