## Iterating Over Arrays

- `sizeof` *strings* will be 32 bytes as it is a `reference datatype`, so doesn't matter how large the string is.

- To know how many elements are in an array, we need the `sizeof` the array, divided by the `sizeof` it's elements.
```cpp
#include <iostream>

int main(){
    char grades[] = {'A', 'B', 'C', 'D', 'F'};

    for (int i = 0; i < sizeof(grades)/sizeof(char); i++){
        std::cout << grades[i] << '\n';
    }

    return 0;
}
```