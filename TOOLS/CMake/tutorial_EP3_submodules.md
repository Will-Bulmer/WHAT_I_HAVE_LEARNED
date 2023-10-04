## Git Submodules (adding glfw windowing library example)

Git submodules allow you to include another Git repository inside your main repository. Useful for external libraries.

### 1. Git Basics
- **Initialize a new git repository**:
```bash
git init
```
- **`.gitignore`**: For CMAKE and cpp,
```txt
# Compiled files
*.o; *.dll; *.exe; *.out; *.so; *.dylib; *.lib; *.a; *.obj; *.mod; *.smod; *.gch; *.pch; *.lai; *.la; *.slo; *.lo

# CMake files
CMakeLists.txt.user; CMakeCache.txt; CMakeFiles; CMakeScripts; Testing; Makefile; cmake_install.cmake; install_manifest.txt; compile_commands.json; CTestTestfile.cmake; _deps

# Build directories
[Bb][Uu][Ii][Ll][Dd]/
```

### 2. Introducing GLFW
- **Adding as a submodule**: 
```bash
git submodule add <GLFW repo URL> <path to where GLFW should be in your project>
```
- **Staging:** In Git, "staging" means preparing your changes for a commit. When you add a submodule, you'll notice two main changes: a `.gitmodules` file and the submodule directory. Both need to be staged (or added) for the next commit.
```bash
git add .gitmodules <path to GLFW>
```
- **Scripts for Convenience:**
    - `configure.sh` to set up the build system.
    ```txt
    #! /bin/sh
    cmake -S . -B out/build
    ```
    - `build.sh` to compile the code.
    ```txt
    #! /bin/sh
    cd out/build ; make
    ```
    - `run.sh` to execute the compiled code
    ```txt
    #! /bin/sh
    cd out/build ; ./OLAS
    ```

Make these scripts executable using:
```bash
chmod +x <script_name>.sh
```

### 3. CMake Integration
- Add the submodule directory to your root `CMakeLists.txt` file:
```cmake
add_subdirectory(<path to GLFW>)
```
- Configure CMake with certain options using `-D`. Eg. Skipping building GLFW docs:
```bash
cmake -DGLFW_BUILD_DOCS=OFF -S . -B out/build
```
- After configuration, use your build script to compile everything.

### 4. Keeping Submodules Updated
When someone clones your repository, they'll also need to fetch the contents of the submodules. This can be done using:
```bash
git submodule update --init --recursive
```
which initializes, fetches, and checks out the submodules content.

### 5. CMAKE vs `#include`
1. **Avoid Hardcoded Paths**: CMake can find the required packages and set up paths dynamically.
2. **Complex Dependency Management**: Ensuring nested dependencies are present and correctly configured is non-trivial. Also checks version compatibility.