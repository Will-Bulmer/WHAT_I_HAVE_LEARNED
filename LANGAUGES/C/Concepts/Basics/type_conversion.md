## Type Conversion

Type conversion is the conversion of a value of one data type to another.
We can do it via.,
**Implicitly** = automatic
**Explicitly** = Precede value with new data type (int)

### Implicit Cast
```cpp
int x = 3.14; // Implicitly truncated to 3.
```

### Explicit Case
```cpp
double x = (int) 3.14; // Cast to an int and stored as a double.
std::cout << (char) 100; // Cast to `d`
double score = correct/ (double)questions * 100;
```