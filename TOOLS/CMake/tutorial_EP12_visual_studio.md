## Visual Studio (OpenGL & Vulkan examples)

### 1. Prerequisite:vcpkg
Use `vcpkg` to manage C++ libraries on Windows. First, make sure to integrate it with your environment:
```bash
vcpkg integrate install
```
After running the command, you'll get an output similar to:
```txt
CMake projects should use: "-DCMAKE_TOOLCHAIN_FILE=E:/src/vcpkg/scripts/buildsystems/vcpkg.cmake"
```
This line tells CMake where to find the libraries installed by `vcpkg`

### 2. OpenGL Project Setup
To set up an OpenGL projet, ensure you have the necessary libraries like `glm`, `glad` and `glf3`.

Here is a smaple `CMakeList.txt`
```cmake
# CMakeLists.txt for the demofaze OpenGL project
cmake_minimum_required (VERSION 3.8)

# Find the necessary packages
find_package(glm CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glfw3 CONFIG REQUIRED)

# Define the project's executable with its source files
add_executable (demofaze "demofaze.cpp" "demofaze.h")

# Link the required libraries to the project
target_link_libraries(demofaze PRIVATE glm::glm glad::glad glfw::glfw)
```
### 2. Vulkan Project Setup
For a Vulka project, the Vulkan SDK should be installed. Here's a sample `CMakeLists.txt` for a Vulkan project:
```cmake
# CMakeLists.txt for the demofaze Vulkan project
cmake_minimum_required (VERSION 3.8)

# Find the Vulkan package
find_package(vulkan REQUIRED)

# Define the project's executable with its source files
add_executable (demofaze "demofaze.cpp" "demofaze.h")

# Specify the include directory for Vulkan headers
include_directories(E:/VulkanSDK/1.2.141.2/include)

# Link the Vulkan libraries to the project
target_link_libraries(demofaze PRIVATE ${VULKAN_LIBRARIES})
```

When specifying libraries, using `${LIBRARY_NAME_LIBRARIES}` ensures that the found libraries are correctly linked. The `include_directories()` command specifies where CMake can find additional header files.
