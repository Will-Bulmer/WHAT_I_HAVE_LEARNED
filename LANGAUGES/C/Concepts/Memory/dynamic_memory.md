## Dynamic Memory

- **Dynamic memory** is memory that is allocated after the program is already compiled and running.
- Use the **new** operator to allocate memory in the **heap** rather than the **stack**.
- Useful when we don't kno how much memory we will need. Makes our programs more flexible especially when accepting *user input*.

```cpp
#include <iostream>

int main(){

    int *pGrades = NULL;
    int size;

    std::cout << "How many grades to enter in?: ";
    std::cin >> size;

    pGrades = new char[size]; // Heap

    for(int i = 0; i < size; i++){
        std::cout << "Enter grade #" << i + 1 << ": ";
        std::cin >> pGrades[i];
    }
    for(int i = 0; i < size; i++){
        std::cout << pGrades[i] << " ";
    }

    delete pGrades; // Pair with the `new` operator. Prevent memory leak.
    return 0;
}
```