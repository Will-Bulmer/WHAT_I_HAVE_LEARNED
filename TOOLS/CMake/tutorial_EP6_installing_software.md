## Installing Your Software (1/2)

Software should be easy to install and run without delving into build process. We automate it usiing install and make install.

### 1. Setting up Installation in CMake
In top-level `CMakeLists.txt`, use the `install()` command to specify the targets and files to install and their destination paths:

```cmake
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES "${PROJECT_BINARY_DIR}/OLASConfig.h" DESTINATION include)
```

### 2. Installing the Software
Default installation prefix is `usr/local` on UNIX. Can be customized using `CMAKE_INSTALL_PREFIX`

`install.sh`:
```sh
#! /bin/sh

cd out/build ; make install
```

