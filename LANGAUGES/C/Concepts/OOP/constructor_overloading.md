## Constructor Overloading

- **Overloaded Constructors** = multiple constructors with the same name but different parameters.
- Allows for varying arugments when instantiating an object.

```cpp
#include <iostream>

class Pizza{
    public:
        std::string topping1;
        std::string topping2;
    Pizza(){
    }
    Pizza(std::string topping1){
        this->topping1 = topping1;
    }
    Pizza(std::string topping1, std::string topping2){
        this->topping1 = topping1;
        this->topping2 = topping2;
    }
};

int main(){
    Pizza pizza1("pepperoni");
    Pizza pizza2("mushrooms", "peppers");

    std::cout << pizza1.topping1 << '\n';

    return 0;
}
```