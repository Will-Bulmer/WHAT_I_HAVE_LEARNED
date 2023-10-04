## Versioning Source Code

Versioning helps identifying and tracking the progress of your software. 

### 1. Setting a Version
In `CMakeLists`,
```cmake
project(OLAS VERSION 1.0)
```
### 2. Propagating Version Information
Want source code to be aware of the version it's built with.
- **Generate a Configuration Header**: Use `configure_file`,
    ```cmake
    configure_file(OLASConfig.h.in OLASConfig.h)
    ```
    with syntax `configure_file(<input-template-file>, <output-header>)`
- **Specify the Include Directory**:
After generating header file, inform CMake where to find it.
    ```cmake
    target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_BINARY_DIRECTORY})
    ```
    with `${PROJECT_BINARY_DIRECTORY}`

### 3. Creating the Configuration Template
- Create file `OLASConfig.h.in` in root.
```c++
#define OLAS_VERSION_MAJOR @PROJECT_VERSION_MAJOR@
#define OLAS_VERSION_MINOR @PROJECT_VERSION_MINOR@
```

### 4. Update CMake
```bash 
cmake -S . -B out/build
```