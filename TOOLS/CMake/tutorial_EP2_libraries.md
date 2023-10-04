## Libraries | Installing | Pairing with Executables

#### Header Guards
- This is simpler and doesn't require unique macro names.
```c++
#pragma once
```
or
```c++
#ifndef
#define
#endif
```

#### Namespaces
- To ensure that functions from different headers do not contradict, we put them in `namespaces`:
```c++
namespace mearlymath {
    int add(int a, int b);
    float add(float a, float b);
}
int mearlymath::add(int a, int b){
    return(a+b);
}
```
### 1. `add_library`
The `add_library` command creates a new library target. This mean CMake will generate build system rules to create a library from the source files you specify.
*Syntax:*
```cmake
add_library(<name> [STATIC|SHARED|MODULE] source1 source2 ... sourceN)
```
- `<name>`: Name of the new library target
- `STATIC|SHARED|MODULE`: Library type. If none are provided, it defaults to `STATIC` or `SHARED`
 based on the `BUILD_SHARED_LIBS` variable.
- `source1, source2, ...`: Source files to compile into the library

*Example:*
```cmake
add_library(mearlymath adder.cpp)
```
### 2. `target_include_directories()`
Command used during **compilation phase**. Tells compiler where to look for header files.
**Simple**: Here's where you can find the declaration for things I've used.
*Syntax:*
```cmake
target_include_directories(my_target PUBLIC/PRIVATE/INTERFACE path/to/headers)
```

### 3. `target_link_directories`
**Linking a target** means connecting a given target (exe) with the necessary libraries. Used during **linking phase**.
**Simple**: Here's the actual code for the header functions.
*Syntax:*
```cmake
target_link_directories(<target> [BEFORE] [PRIVATE|PUBLIC|INTERFACE] <dir1> [<dir2>...])
```
- `<target>`: Specifies the target to link directories to.
- `PRIVATE|PUBLIC|INTERFACE`: Scope of the directories
    - `PRIVATE`: Directories are used for this target
    - `PUBLIC`: Directories are used for this target and those that link this target
    - `INTERFACE`: Directories are used for targets that link this one.
- `<dir1>, <dir2>, ...`: Directories containing libraries.

*Example:*
```cmake
target_link_directories(testsome PRIVATE ${CMAKE_SOURCE_DIR}/../../SomeLibDemo/cpp/build/)
```

### 4. `set_target_properties`
The `set_target_properties` command sets properties on a target. For example, it can be used to specify which files are public headers.
*Syntax:*
```cmake
set_target_properties(<target1> <target2> ... PROPERTIES <prop1> <value1> <prop2> <value2> ...)
```
- `<target1>, <target2>, ...`: Targets for which to set properties.
- `<prop1>, <prop2>, ...`: Property names.
- `<value1>, <value2>, ...`: Corresponding values for properties.

*Example:*
```cmake
set_target_properties(mearlymath PROPERTIES PUBLIC_HEADER adder.h)
```

### 5. `install`
The `install` command indicates how to install various files and targets. This can be used to specify the installation paths for libaries, executables, headers, etc
*Syntax(for targets)*:
```cmake
install(TARGETS <target1> [<target2>...] DESTINATION <path> [...])
```
- `<target1>, <target2>, ...`: Targets to install.
- `<path>`: The installation path.

*Example:*
```cmake
install(TARGETS mearlymath LIBRARY DESTINATION lib PUBLIC_HEADER DESTINATION include)
```

### 6. Building with CMAKE
```bash
mkdir build/
cd build/
cmake -S ..
make
```
