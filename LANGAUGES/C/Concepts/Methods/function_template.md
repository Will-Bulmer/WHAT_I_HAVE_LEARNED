## Function Template

- A funtion template describes what a function looks like. Can be used to generate as many overloaded functions needed, each using different data types.

### Overloading
- Creating 3 overloaded functions is a lot of work.
```cpp
#include <iostream>

int max(int x, int y){
    return (x > y) ? x : y;
}

double max(double x , double y){
    return (x > y) ? x : y;
}

char maxx(char x, char y){
    return (x > y) ? x : y;
}

int main(){
    std::cout << max(1.1, 2.1) << '\n';

    return 0;
}
```

### Function Templates
- **T** is a common naming convention.
```cpp
#include <iostream>

template <typename T, typename U>

auto max(T x, U y){
    return (x > y) ? x : y;
}
int main(){
    std::cout << max(1, 2.1) << '\n';

    return 0;
}
```