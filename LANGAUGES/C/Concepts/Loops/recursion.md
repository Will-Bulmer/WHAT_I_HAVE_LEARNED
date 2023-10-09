## Recursion
- **Recursion** is a programming technique where a function invokes itself from within. Break a complex concept into a repeatable single step.

### Recursive VS Iterative
- **Advantages**: less code and is cleaner. Useful for sorting and searching algorithms.
- **Disadvantages**: Uses more memory. Slower.


### ITERATIVE
```cpp
#include <iostream>
void walk(int steps);

int main() {
    walk(100);
    return 0;
}
void walk(int steps){
    for(int i = 0; i < steps; i++){
        std::cout << "You take a step!\n";
    }
}
```

### RECURSIVE
When you invoke a function, you add what is called a frame to the **stack**. When it attempts to access memory beyond the call stack's bounds, the stack is said to overflow (**stack overflow**).
```cpp
#include <iostream>

void walk(int steps);

int main(){
    walk(100);
    return 0;
}
void walk(int steps){
    if(steps > 0){
        std::cout << "You take a step!\n";
        walk(steps - 1);
    }
}
```