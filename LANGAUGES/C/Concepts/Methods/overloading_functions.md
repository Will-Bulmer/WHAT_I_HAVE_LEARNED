## Overloading Functions

You can have different versions of the same function. The function and it's parameters is the function's `signature`. Functions with the same name must have different parameters.

```cpp
#include <iostream>
void bakePizza();
void bakePizza(std::string topping1); // Function Signature

int main() {

    bakePizza();
    return 0;
}

void bakePizza(){
    std::cout << "Here is your pizza!\n";
}
void bakePizza(std::string topping1){
    std::cout << "Here is your " << topping1 << " pizza!\n";
}
```