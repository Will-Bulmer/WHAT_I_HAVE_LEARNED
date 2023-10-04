## CDash (CTest continued)


### 1. What is CDash?
CDash is an open-srouce, web-based software testing server. It aggregates, analyzes, and displays the results of software testing processes submitted from clients located around the world. Developers depend on CDash to convey the state of a software system, and to continually improve its quality. CDash is a part of a larger software process that integrates Kitware's CMake, CTest and CPack tools, as well as other external packages.

**Key Features:** 
- **Dashboard Summaries**: Gives a bird's eye view of the software quality.
- **Interactive Reports**: Drill-down into build,test and coverage details.
- **Customizable Views**: Filter & view data the way you want.
- **Integration with VCS**: Links directly to your version control system for easy traceability.
- **Integration with CTest**: Works seamlessly with CTest, a testing tool distributed as part of CMake.

### 2. Using CDash with CMake and CTest
1. Setting up Testing:
In your main `CMakeLists.txt`
```cmake
if(TEST_ADDER)
    enable_testing()
    add_subdirectory(tests)
    include(CTest)
endif()
```

2. Creating Tests:
In your tests' `CMakeLists.txt`:
```cmake
add_executable(math_test tester.cpp)
target_link_libraries(math_test PUBLIC ${EXTRA_LINKS})

add_test(NAME "Math.Adder.Test1" COMMAND math_test 1 6)
add_test(NAME "Math.Adder.Test2" COMMAND math_test 2 8)
# ... Additional tests ...
```

3. Configuring for CDash:
Your `CTestConfig.cmake` configures how CTest should submit the results to CDash:
```cmake
set(CTEST_PROJECT_NAME "OLAS")
set(CTEST_NIGHTLY_START_TIME "01:00:00 UTC")

set(CTEST_DROP_METHOD "https")
set(CTEST_DROP_SITE "my.cdash.org")
set(CTEST_DROP_LOCATION "/submit.php?project=OLAS")
set(CTEST_DROP_SITE_CDASH TRUE)
```
Here:
- `CTEST_PROJECT_NAME` specifies the name of your project on CDash.
- `CTEST_NIGHTLY_START_TIME` determines when the "nightly" cycle starts.

### 3. Submitting Tests to CDash
Once everything is set up, you can run `ctest` with the `-D Experimental` argument to build, test and submit the results to CDash.
