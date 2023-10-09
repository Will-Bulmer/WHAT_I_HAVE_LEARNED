## Inheritance

- **Inheritance** = a class can recieve attributes and methods from another class.
- *Children* classes inherit from a *Parent* class.
- Helps to reuse similar code found within multiple classes.

```cpp
#include <iostream>

class Animal{
    public:
        bool alive = true;
    void eat(){
        std::cout << "This animal is eating\n";
    }
};
class Dog : public Animal{
    public:
    
    void bark(){
        std::cout << "The dog goes woof!\n";
    }
};

int main(){

    Dog dog;
    std::cout << dog.alive << '\n';
    dog.eat();

    return 0;
}
```