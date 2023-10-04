## Running CMake on Windows (like linux)

### 1. Setting Environment Variables
To use command-line tools like CMake and Git in the Windows terminal, you need to ensure their executable paths are included in the system's PATH environment variables

**Steps:**
1. **Open Windows PowerShell**
2. **Check if CMake and Git are in the PATH**:
    - Simply type `cmake --version` and `git --version`. If both commands return versions, they're already in PATH.
3. **Add CMake and Git to PATH if they aren't already**:
    - Right-click on the `Start` button and select `System`.
    - Click on the `Advanced system settings` link on the right.
    - Click on the `Environment Variables` button at the bottom.
    - Under "User varaibles", find the `Path` variable, then click `Edit`.
    - Add the paths `C:\Program Files\CMake\bin` and `C:\Program Files\Git\bin` to the list.

## 2. Compiler Options on Windows
By default, Windows does not come with the GCC compiler used in many Linux system. However, there are a couple of way to use GCC or similar compilers on Windows:

1. **Windows Subsystem for Linux (WSL):** WSL allows you to run a Linux distriubtion alongisde your existing Windows installation. With WSL, you can install and use GCC just as you would on a Linux machine.
2. **MinGW:** This is a free and open-source software development environment to create Microsoft Windows applications. If you want to use CMake with MinGW, you might generate build files with a command like `cmake -G "MinGW Makefiles`.
3. **Visual Studio:** If you have Visual Studio installed, you can also use its compiler (MSVC) with CMake.

**Note:** If you're using VSCode, it might not recognize CMake unless you have the CMake extension instlalled. This extension provides enhanced support for CMake in VSCode, with features like IntelliSense and automatic build system system.

### 3. MSBuild
**What is MSBuild?**

MSBuild (Microsoft Build Engine) is Microsoft's build tool for Visual Studio. It compiles MSVC projects (.vcxproj) by reading the project files and produces executable, library, or packaged output. Essentially, it's the build system used by Visual Studio, akin to `make` in Linux.

**Where to find MSBuild.exe:**

If you're using CMake with the Visual Studio generator, you might need `MSBuild.exe` to build your projects from the command line. Here's how to locate it:

- Typically, MSBuild is found under the Visual Studio installation directory: C:\Program Files (x86)\Microsoft Visual Studio\<version>\<edition>\MSBuild\Current\Bin.

**Adding MSBuild.exe to PATH:**

1. Follow the steps under "Setting Environment Variables" above.
2. Add the path to MSBuild (e.g., `C:\Program Files (x86)\Microsoft Visual Studio\<version>\<edition>\MSBuild\Current\Bin`) to the list.
