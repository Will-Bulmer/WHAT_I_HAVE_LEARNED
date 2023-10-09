## Section 1: The Basics

Notes taken from the video: https://www.youtube.com/watch?v=ZzaPdXTrSb8
In this video ,will learn about:
- Variables and constants
- Naming conventions
- Mathematical expressions
- Writing to and reading from the console
- Working with the standard library
- Comments

### 1. Variables
```cpp
// Initializing
int file_size = 100;
double sales = 9.99;
int unitialized;

// If we print `unitialized`, we recieve garbage. This is the data that is current in memory.

// Best practice is declaring varaibles on separate lines.
```

### 2. Constants
```cpp
const double pi = 3.14;
pi = 0; // Error
```

### 3. Naming Conventions
```cpp
int file_size; // Snake Case
int FileSize; // Pascal Case
int fileSize; // Camel Case
int iFileSize; // Hungarian Notation
```

### 4. Mathematical Expressions
```cpp
int x = 10;
int y = 3;
int z = x + y; // Addition operator on two operands

// DIVISION
int z = x / y; // Integer Division
double z = x / y; // Still integer division
double z = x*(1.0) / y

int z = x % y; // Modulus Operator

// INCREMENT OPERATORS
y = x++; // Assigned x, then x incremented: y = 10, x = 11
y = ++x; // Assigned incremented x: y = 11, x = 11
```

### 5. Priority of Operators
In math, multiplication and division have a higher priority.
```cpp
// * and /
// + and -
double = x = 1 + 2 * 3
```

### 6. Writing Output to the Terminal
- std::cout : Standard Output Stream
- << : Stream Insertion Operator
- std::endl : End of Line

With proper formatting, we get,
```cpp
std::cout << "x = " << x << std::endl
          << "y = " << y;
```

We can simplify the code further,
```cpp
using namespace std;

cout << "x = " << x << endl
     << "y = " << y;
```
### 7. Reading Data from the Terminal
- std::cin : Standard Input Stream
- >> : Stream Extraction Operator
- ```cpp
- cin >> x >> y;
- cout << x + y;
- ```

### 8. Writing to the Console
Useful math function from <cmath> include:
- floor() : Round down a value
- ceil() : Round up a value
- pow()
- sqrt()

### 9. Comments
- More conventional to write the comment around a line.
- Use comments to explain `whys` and `hows` (or assumptions)