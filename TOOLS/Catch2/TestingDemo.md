## Catch2

### 1. Setting up Catch2
Since Catch2 is header-only, the simplest way to integrate it is to add the single include file to your project. Download `catch.hpp` from the **Catch2 repository**

### 2. Create a Test File
- Create a new file for your tests. For this example, we'll name it `tests_main.cpp`
```cpp
#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() function.
#include "catch.hpp"
```
- The `CATCH_CONFIG_MAIN` macro instructs Catch to genrate a `main()` function for the test runner in this file.

### 3. Writing Your First Test
Let's start TDD. Suppose you're going to create a function called `add` that adds two numbers. First, write a test for this function:
```cpp
TEST_CASE("Adding two numbers", "[add]") {
    REQUIRE(add(1, 1) == 2);
    REQUIRE(add(3, 4) == 7);
}
```
Notice that we haven't written the `add` function yet. This is the essence of TDD - you start with a failing test.

### 4. Compiling and Running the Test
Compile `test_main.cpp` with your C++ compiler. When you run it, the test will fail since the `add` function doesn't exist.

### 5. Implementing the Function
Now, you'll write the `add` function to make the test pass:
```cpp
int add(int a, int b) {
    return a + b;
}
```

### 7. Organizing Tests with Sections
Within `TEST_CASE`, you can further organize tests with sections.
```cpp
TEST_CASE("Numbers are processed", "[math]") {
    SECTION("Addition") {
        REQUIRE(add(1, 1) == 2);
        REQUIRE(add(2, 2) == 4);
    }
    SECTION("Subtraction (not yet implemented)") {
        REQUIRE(subtract(5, 3) == 2);
    }
}
```