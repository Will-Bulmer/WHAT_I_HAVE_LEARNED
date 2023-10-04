## find_library(...) (1/2)

When developing software, it's common to leverage external libraries. In open-source projects, it's frequent to include these libraries as submodules, thought this isn't the universal standard. If a required library isn't available during the build process, linking errors will arise.

### 1. Using `find_library`
*Syntax:*
```cmake
find_library(VARIABLE_NAME library_name
             NAMES alternative_name1 alternative_name2 ...
             PATHS path1 path2 ...
             HINTS hint_path1 hint_path2 ...
             PATH_SUFFIXES suffix1 suffix2 ...
             NO_DEFAULT_PATH
             DOC "documentation_string")
```
- **VARIABLE_NAME**: This is the variable that will store the path to the found library.
- **library_name**: The primary name of the library, without common prefixes like lib.
- **NAMES**: Alternative names of the library. CMake presumes these names might have a lib prefix.
- **DOC**: A documentation string that provides more information about the library or its purpose.
- **PATHS**: Directories explicitly mentioned to search for the library.
- **HINTS**: Suggested directories where the library might be located. These are checked before the PATHS.
- **PATH_SUFFIXES**: Specifies any subdirectories within the provided paths to search.
- **NO_DEFAULT_PATH**: If enabled, CMake will only consider the provided PATHS and HINTS, ignoring the system's default search paths.

*Example with Error Handling*:
```cmake 
find_library(myglewlib NAMES glew glew2 GLEW GLEW2 
             DOC "Locating the glew library")

if(NOT myglewlib)
    message(FATAL_ERROR "GLEW library not found.")
else()
    message(STATUS "GLEW library found at: ${myglewlib}")
endif()
```

*Important Notes*: Once CMake locates the library, it stores the path in its cache. This means that, on subsequent configuration, CMake won't re-search for the library unless the cache is cleared or modified.

