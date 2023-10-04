## Understanding the Basics

### 1. Makefiles
Define a set of tasks to be executed. CMAKE can generate these files for various platforms and compilers.
**Example Makefile:**
```makefile
default:
    g++ main.cpp -o out.exe
```
- `o` is output file
- Makefiles do not accept spaces; use tabs for indentation
- Execute with the command `make`
- Gets `out.exe`. Execute with `./out.exe`

### 2. Useful Bash Commands
BASH stands for 'Bourne-Again SHell'. Uses scripting language which uses an interpreter. Uses `tokenization` (breaks input into tokens). Tokens are structured into an `abstract syntax tree (AST)` which represents the hierachical nature of the script commands. Intrepeter is written in C.
#### Working with CMAKE
- CMake uses a top-level configuration file named `CMakeLists.txt`.
- To run CMake, specify your `source` directory and the `build` directory.

```bash
cmake -S <path-to-source> -B <path-to-build>
```

#### Common Practices with CMake
1. Create a `build` directory to contain the generated files:
```bash
mkdir build/
```

2. Navigate to the build directory and run CMake, pointing it to the source:
```bash
cd build/
cmake -S ../../ -B .
```
You will notice several generated files and directories.
- `CMakeCache.txt`: Stores cache variables, path dependencies.
- `CMakeFiles`
- `cmake_install.cmake`: Handels installss
- `Makefile`: The file that CMAKE produces. Use with `make` tool.

3. Execute the MakeFile in the directory. Looks for first file:
```bash
make
```


#### Basic File Operations
1. Create an empty file:
```bash
touch new_file.txt
```
2. Remove a file or directory:
```bash
rm <filename>
```
3. Remove a directory and its contents. `r` recursive, `f` force:
```bash
rm -rf <directory-name>
```
4. Create nested directories in one command:
```bash
mkdir -p out/build
```
5. View the contents of a file, such as a makefile
```bash
cat makefile
```
6. Concatenate Multiple Files:
```bash
cat file1.txt file2.txt > combined.txt
```
7. Move file locations. Move SomeLibDemo to src.
```bash
mv SomeLibDemo/ src/
```

### 3. CMakeLists.txt Basics
This is the central configuration file for CMake
**Smaple CMakeLists.txt:**
```cmake
cmake_minimum_required(VERSION 3.13.4)
project(OLAS)
add_executable(${PROJECT_NAME} main.cpp)
```
- Creates PROJECT_NAME variable called 'OLAS'. Also defines:
    - `PROJECT_SOURCE_DIR`: source directory of current project.
    - `PROJECT_BINARY_DIR`: Build directory for the current project.
- `add_executable` specifies source files (main.cpp) and creates and executable called (PROJECT NAME)


