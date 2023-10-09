## Do-While Loop

do-while loop = do some block of code first, 
                THEN repeat again if condition is true

First will display a while-loop and then see how a do-while will be better:
```cpp
#include <iostream>

int main(){
    int number;

    std::cout << "Enter a positive #: ";
    std::cin >> number;

    while(number < 0){
        std::cout << "Enter a positive #: ";
        std::cin >> number;
    }
    std::cout << "This # is:" << number;
    return 0;
}
```

Here is with the do-while:
```cpp
#include <iostream>

int main(){
    int number;

    do{
        std::cout << "Enter a positive #: ";
        std::cin >> number;
    }while(number < 0);

    std::cout << "The # is: " << number;
    return 0;
}
```