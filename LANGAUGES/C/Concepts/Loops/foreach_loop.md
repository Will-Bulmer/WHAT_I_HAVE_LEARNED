## Foreach Loop

- foreach loop = loop that eases the traversal over an iterable data set.

```cpp
#include <iostream>

int main() {
    std::string students[] = {"SpongeBob", "Patrick", "Squidward"};
    
    // Standard ForLoop
    for(int i = 0; i < sizeof(students)/ sizeof(students[0]); i++){
        std::cout << students[i] << '\n';
    }
    
    // ForEach loop, we start at the beginning and go to the end, less flexibility.
    for(std::string student : students){
        std::cout << student << '\n';
    }

    return 0;
}
```