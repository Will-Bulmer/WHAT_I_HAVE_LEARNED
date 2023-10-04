## VSCODE | VCPKG Libraries | Project Setup Basics

Here is a basic CMakeLists.txt file for VCPKG library.

```cmake
# set(CMAKE_TOOLCHAIN_FILE "E:/src/vcpkg/scripts/buildsystems/vcpkg.cmake")

project(demo)

add_executable(${PROJECT_NAME} main.cpp)

set(CMAKE_PREFIX_PATH "E:/src/vcpkg/installed/x64-windows/share")

find_package(fmt CONFIG REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)
```