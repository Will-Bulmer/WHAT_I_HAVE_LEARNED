## Enums
- Enums = a user-defined data type that consists of paired named-integer constants.
- GREAT if you have a set of potential options.

```cpp
#include <iostream>

enum Day {sunday = 0, monday = 1, tuesday = 2, wednesday = 3, thurday = 4, friday = 5, saturday = 6};
// 0-6 is implicitly assigned.

int main () {

    //std::string today = "sunday"; // CANNOT use in switch
    Day today = sunday;

    switch(today){
        // Could use case 0 
        case sunday: std::cout << "It is Sunday!\n";
                        break;
        // ... 
    }
    return 0;
}
```