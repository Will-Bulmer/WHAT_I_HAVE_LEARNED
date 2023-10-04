## find_package modules and config options (2/2 of find libs)

When developing software, especially cross-platform applications, handling dependencies is crucial. CMake simplifies this with mechanisms like find_library() and find_package(). The idea is to abstract away the details of where and how libraries are installed.

### 1. `find_library()`
The `find_library()` command searches for a specific library file.
*Example searches for the GLEW library:*
```cmake
find_library(myglewlib glew NAMES glew2 GLEW GLEW2 glew32
PATHS "D://Development Libraries\\glew-2.1.0"
PATH_SUFFIXES "lib\\Release\\x64" "bin\\Release\\x64")
```

**Drawbacks:**
- **Hard-coded paths**
- **Platform-specific**

### 2. `find_package()`
The `find_package()` command is more sophisticated. It release on "Find Modules" or package configuration files provided by the libraries themselves.

```cmake
set(CMAKE_MODULE_PATH cmake)
find_package(GLEW MODULE REQUIRED)
```
The above sets a module path, then looks for GLEW. If found, you can utilize variables like `GLEW_INCLUDE_DIRS` and `GLEW_LIBRARIES`.

**Benefits**:
- **Abstraction**: No need to worry about absolute paths.
- **Cross-platform**

### 3. Handling Git Submodules
Git submodules let you nest one repositor inside another. The following ensures submodules are correctly initialized and updated:
```cmake
find_package(Git QUIET)

if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init failed with ${GIT_SUBMOD_RESULT}, please checkout submodule")
        endif()
    endif()
endif()
```
This script checks if Git is available, verifies the project is a Git repository, and then updates the submodules.

### 4. Crafting Your Own Find Modules
Sometimes, a library doesn't offer a CMake package configuration file. In such cases, you may have to write your own find module (like FindGLEW.cmake). These modules usually set variables indicating the found status, include directories, library paths, etc., and are saved in your project's cmake directory (or any directory you specify in CMAKE_MODULE_PATH).

