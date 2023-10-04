## CTest

Using CTest over a simple custom test runner has several advantages.
- **Scalability**: Tests arranged into own modules.
- **Selective Testing**
- **Parallel Execution**
- **Consistent Reporting**
- **Dependency Management**

### 1. Root Directory: Main CMakeLists.txt
At the highest level of your project, you use CMake to:

1. Enable testing with `enable_testing()`.
2. Specify conditions to include subdirectories for specific tests.
3. Manage Git Submodules, ensuring all necessary code components are downloaded and available.
4. Add external dependencies (like `glfw` in this example)

**Snippet Explanation:**
```cmake
# Enables CMake's testing functionalities.
enable_testing()

# Conditionally add graphics tests.
if (TEST_GRAPHICS)
    add_subdirectory(graphics)
endif()

# Conditionally add math tests if the USE_ADDER option is enabled.
if (TEST_MATH AND USE_ADDER)
    add_subdirectory(math)
endif()
```
This snippet defines when to inlude which test directories based on project configurations.

### 2. Graphics Tests: Graphics/CMakeList.txt
This CMakeLists is responsible for:

1. Creating an exectuable for graphics tests.
2. Specifying the directories where header files and libraries can be found.
3. Linking required libraries to the graphics test.
4. Defining the actual test using `add_test`.
5. Installing the test executable.

**Snippet Explanation:**
```cmake 
# Defines the executable for the graphics tests.
add_executable(graphics_test tester.cpp)

# Specifies where the compiler can find additional header files.
target_include_directories(graphics_test PUBLIC ${PROJECT_BINARY_DIR} external/glfw/include ${EXTRA_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS})

# Specifies directories for the linker to find libraries.
target_link_directories(graphics_test PUBLIC external/glfw/src ${EXTRA_LIB_DIRS})

# Links necessary libraries to the graphics_test executable.
target_link_libraries(graphics_test ${EXTRA_LINKS} glfw ${GLEW_LIBRARIES} GL GLU)

# Defines the graphics test and its working directory.
add_test(NAME test1 COMMAND graphics/graphics_test WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Installation directive for the graphics_test executable.
install(TARGETS graphics_test DESTINATION bin)
```

### 3. Math Tests: Math/CMakeList.txt
This CMakeLists does much of the same as the Graphics one, but tailored for math tests.

**Snippet Explanation:**
```cmake
# Defines the executable for the math tests.
add_executable(math_test tester.cpp)

# Specifies where the compiler can find additional header files.
target_include_directories(math_test PUBLIC external/glfw/include ${GLEW_INCLUDE_DIRS})

# Specifies directories for the linker to find libraries.
target_link_directories(math_test PUBLIC external/glfw/src)

# Links necessary libraries to the math_test executable.
target_link_libraries(math_test PUBLIC ${EXTRA_LINKS})

# Defines the math test, its arguments, and its working directory.
add_test(NAME "test1" COMMAND math/math_test arg1 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

# Installation directive for the project's main executable.
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
```

### 4. `add_test`
The `add_test` command is used to define a new test for the project. This command is integral to CMake's testing system. Once tests are added using this command, they can be executed with the `ctest` command. You have to be in the `binary_directory` to run `ctest`.

*Syntax:*
```cmake
add_test(NAME test_name COMMAND command_to_run_test [args...])
```
- `NAME`: The name you want to assign to the test.
- `COMMAND`: The command to run the test. This will often be an exectuable that CMake builds but it could be any other command.

*Example*:
```cmake
add_test(NAME "test1" COMMAND math/math_test arg1 WORKING_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
```
