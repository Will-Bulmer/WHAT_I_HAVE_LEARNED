## Making Libs Optional

In larger projects, might not want to include and link against every available library.

### 1. Defining Options
```cmake
# adder use logic
option(USE_ADDER "A simple library for adding 2 floats" ON)
```

### 2. Conditional Inclusion of the Library
```cmake
if(USE_ADDER)
    add_subdirectory(Adder)

    list(APPEND EXTRA_LIB_DIRS "Adder")
    list(APPEND EXTRA_INCLUDES_DIRS "Adder")
    list(APPEND EXTRA_LINKS adder)
endif()
```

### 3. Setting Targets
```cmake
target_include_directories(${PROJECT_NAME}
${EXTRA_INCLUDES_DIRS})

target_link_directories(${PROJECT_NAME}
${EXTRA_LIB_DIRS})

target_link_libraries(${PROJECT_NAME}
${EXTRA_LINKS})
```

### 4. Configuring Through Header
```c++
#cmakedefine USE_ADDER
```

### 5. Safeguarding Code
Can use preprocessor directives to conditionally include headers.
```cpp
#ifdef USE_ADDER
    #include <adder.h>
#endif
```