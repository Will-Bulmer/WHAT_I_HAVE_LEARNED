## Switch

Here is what it would look with else-if statements.
```cpp
#include <iostream>

int main() {

    int month;
    std::cout << "Enter the month (1-12): ";
    std::cin >> month;

    if (month == 1){
        std::cout << "It is January";
    }
    else if(month == 2){
        std::cout << "It is February";
    }
    // ...
    
    return 0;
}
```

Here is what it would look like with `switch` statements.

```cpp
#include <iostream>

int main(){
    int month;
    std::cout << "Enter the month (1-12): ";
    std::cin >> month;

    switch(month){
        case 1: 
            std::cout << "It is January";
            break;
        case 2:
            std::cout << "It is February";
            break;
        // ...
        default:
        std::cout << "Please enter in only numbers (1-12)";
    }
    return 0;
}
```