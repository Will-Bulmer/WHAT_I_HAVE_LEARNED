## Back to Basics: Test-driven Development

### What kinds of tests are there?
- **Unit Tests**: Tests for a unit of code in isolation.
- **Integration Tests**: Tests for interaction of several components.
- **System Tests**: Tests for the entire software system.
- **Point Tests**: "Unit" test using the whole system as a test driver.
- **Acceptance Tests**: Test for passing certain requirements.

One of the most common reasons for abandoning a test suite is trying to use the wrong kind of tests.

### 1. Unit Tests
- Most commonly used with test-driven development.
- The kind of tests developers run more than any other.
- Most misunderstood.

- Is testing of a unit of code outside of the rest of the program.

#### Unit Testing - What is a Unit?
- *Unit* is a section of code that has a specific function.
- In object-oriented programming, classes are (almost always) units.
- Function, procedures, modules, class methods can be units.
- Units are often small.
- Untis can be large (e.g. Database or collection of previously tested smaller units).

#### Unit Testing - Without the Program?
- Unit testing does not use the rest of the program.
- Where do we get main()? - It's written specifically for each test
  - Doing so by hand is hard
  - There are unit testing frameworks to simplify and automate unit testing.
- Where do we get the test data?
  - More generally, how do we recreate the internal state of the unit to be exactly what we need for the test we want to run?
  - Sometimes it's trivial.
  - It could alse be very difficult (this is mainly why programmers switch to point tests)
  - There are many techniques to manage the test data problem.

#### Unit Testing - Example - Sudoku Puzzle Solver

- Unit: Sudoku class (represents the puzzle)
```cpp
class Sudoku {
    public:
    Sudoku();
    unsigned char get(size_t i, size_t j) const;
    void set(size_t i, size_t j, unsigned char value);
};
```
- Unit Tests using GoogleTest:

```cpp
#include "sudoku.h"                  // Code to test
#include <gtest/gtest.h>            // Unit test framework
TEST(Sudoku, Construct){
    Sudoku S;                       // Should be empty
    EXPECT_EQ(0, S.get(0,0));       // Make sure it is
    EXPECT_EQ(0, S.get(8,8))
}
```
- No main() - provided by framework.

```cpp
TEST(Sudoku, set){
Sudoku S;                   // Already Tested
S.set(0, 0, 5);             // Should fill a cell
EXPECT_EQ(5, S.get(0,0));   // Did it?
EXPECT_EQ(0, S.get(0,2));   // Did it mess anything up?
}
```
- All aspects of the documented behaviour should be tested.
```cpp
TEST(Sudoku, Set){
    Sudoku S;
    S.set(0,0,5);
    EXPECT_THROW(S.get(9,0), std::logic_error);
    EXPECT_THROW(S.set(2, 1, 10), std::logic_error);
    EXPECT_THROW(S.set(0,0,6), std::logic_error);
}
```

#### Test-Driven Development Often Uses Unit Tests
- Emphasizes incremental development.
- We need tests for just the code we have added in the last step.
- Testing is faster if we don't have to build the whole program.
- It is often hard to fully test a unit(component) using the rest of the system as the test driver (hard to create certain inputs).
- The rest of the system may not exist yet!
  - We code in small steps, the first "complete" program does not happen until after many steps.
- There is no rule that TDD must use only unit tests!

#### When to Write Tests
#### 1. Before any code is written (Example-driven design)
- They won't compile
+ They describe how the client code should look like
+ They specify the requirements on the interface in C++ instead of English.
#### 2. After the interfaces are declared
-+ They will compile but won't link
#### 3. After writing a dummy implementaion (Most Common)
+ The minimum needed to compile and run the tests
+ We expect the tests to fail
  - But some won't!
  + We know whether our tests are sensitive enough to detect that we at least tried to write some real code.
-+ Interfaces must be written to the spec (no client code mockup) 

#### How Much Implementation is Enough?
- Don't vectorize, parallelise, optimise, multi-threading, exotic algorithms etc.

#### How Many Tests is Enough?
- We will never have full test coverage
- Triangulate for "normal case"
- Test for all "special cases", "corner cases", etc.
- One of the most common reason for declining testing discipline is that tests take too long to run!

- **Error Handling** is a logically separate function and should be tested in a separate step (could be before or after the normal case)

#### Should Implementation Be Tested?
- YES: many errors cannot be observed through public API's
- NO: Implementation can change, tests will be fragile.
- One of the most common reasons for abandoning a test suite is the need to keep updating the tests.
- Test this only as a last resort.

### Test Double
Dependecy Injection etc. Omitted.

### Testing Multi-Threaded and Concurrent Programs.
- Develop and test each single-threaded component.
- Develop and test synchronization and communication components.
- Implement and test concurrency (in small increments)

Concurrency should be designed into the program from the start.