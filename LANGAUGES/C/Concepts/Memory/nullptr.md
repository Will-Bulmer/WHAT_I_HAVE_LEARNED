## Nullptr

- Null value = a special value tha means something has no value. 
               When a pointer is holding a null value,
               that pointer is not poining at anything (**null potiner**)

- nullpr = keyword represents a null pointer literal
- nullptr are helpful when determining if an address was successfully assigned to a pointer.


It can safegaurd against unexpected results. When working with dynamic memory, it can be good to check if a pointer was assigned
```cpp
#include <iostream>

int main(){
    int *pointer = nullptr;
    int x = 123;

    pointer = &x;
    if (pointer == nullptr){
        std::cout << "address was not assigned!\n";
    }
    else{
        std::cout << "address was assigned!\n";
    }

    return 0;
}
```