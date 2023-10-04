## Installing with CPack (2/2)

Makes installation of software easier. No need to go into build processes.

### 1. Setup CPack Configuration in CMakeLists.txt
At top-level,
```cmake
# Include necessary system libraries that the installer should package with the application
include(InstallRequiredSystemLibraries)


set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")

set(CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")

include(CPack)
```

### 2. Generate Installers
Then, navigate to the build directory,
```bash
cd  path/to/build/directory
```
Then run:
```bash
cpack
```

### 3. Run the Installer
```bash
./OLAS--Linux.sh
```
When executed, creates the following directories: `bin`, `include`, `lib` and `share`.

