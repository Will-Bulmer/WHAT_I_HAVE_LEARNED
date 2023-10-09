## Section 2: The Fundamental Data Types

Notes taken from the video: https://www.youtube.com/watch?v=ZzaPdXTrSb8
In this video ,will learn about:
- Built-in types
- Numbers
- Boolean values
- Characters and strings 
- Arrays

### 1. Fundamental Types
C++ / C#/ Java are statically-typed langauges. Once we declare a variable type, we cannot change it.

Python / JavaScript/ Ruby are dynamically-typed langauges.

| Type          | Bytes                  | Range                                      |
|---------------|------------------------|--------------------------------------------|
| `bool`        | 1 (typically)          | `true` or `false`                          |
| `char`        | 1                      | -128 to 127 (or 0 to 255 for `unsigned`)   |
| `short`       | 2                      | -32,768 to 32,767                          |
| `int`         | 4 (typically)          | Platform-dependent (often -2¹⁵ to 2¹⁵-1)   |
| `long`        | 4 or 8 (typically)     | -2³¹ to 2³¹-1 (for 4 bytes)                |
| `long long`   | 8                      | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| `float`       | 4                      | Approximately ±3.4E±38 (7 digits precision)|
| `double`      | 8                      | Approximately ±1.7E±308 (15 digits precision)|
| `long double` | 8 or more (typically)  | Varies, often greater precision than `double`|

### 2. Initializing Variables
When working with floats, always declare it with an 'f' otherwise, the compiler will automatically assume it is a double and it can result in data loss.
```cpp
float interestRate = 3.67F;
float interestRate = 3.67f;
```
Same with long. If you don't include the 'L', then the compiler will treat it as an int
```cpp
long fileSize = 90000l;
long fileSize = 90000L;
```
Other examples:
```cpp
char letter = 'a';
auto isValid = false; // Compiler auto-assigns.
```

One more way to initialize variables is to use **Brace Initialization**
```cpp
int number = 1.2; // Runs, but is bad
int number{1.2}; // Stops mistakes

int number {}; // number = 0
int number; // number = garbage
```

### 3. Working with Numbers
Using only 6 digits, we can represent any colour:
- RGB = Red Green Blue
         FF  00    00

```cpp
int number = 255;
int number = 0b11111111; // Returns 255
int number = 0xff; // Returns 255

unsigned int number = -255; // Returns garbage. Stay away from it. Unpredicable.
```

### 4. Narrowing
Initialize a variable of a smaller type using a variables of a larger type.
```cpp
int number = 1'000'000;
short another = number; // Returns 16900 which is narrowing
sort another{number}; // This won't  compile. This is much safer.

short number = 100;
int another = number; // Non-issue. No data loss.
```

### 5. Generating Random Numbers
Using `<cstdlib>`, with the `rand` method:
```cpp
int number = rand(); // Won't generate a random number as it's actaully based of a function. So you get a random number, but it's the same one each time.
srand(5); // Also same issue
```
How can we get truly random numbers? What if we use the number of seconds elapsed since january 1970?
```cpp
#include <ctime>

long elapsedSeconds = time(nullptr); // Jan 1 1970

// Use the elapsedSeconds to seed the random number generator.
// Include modulus to set the upper limit.
srand(elapseedSeconds);
int number = rand() % 10;
cout << number;
```

