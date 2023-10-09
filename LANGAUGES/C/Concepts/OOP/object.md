## Object

- **object** is a collection of attributes and methods.
- They can have characteristics and could perform actions.
- Can be used to mimic real world items (ex. Phone, Book, etc.)
- Created from a **class** which acts as a "blue-print"

```cpp
#include <iostream>

class Human{
    public:
        std::string name;
        std::string occupation;
        int age;

        void eat(){
            std::cout << "This person is eating\n";
        }
        void drink(){
            std::cout << "This person is drinking\n";
        }
        void sleep(){
            std::cout << "This person is sleeping\n";
        }
};

int main() {
    Human human1;

    human1.name = "Rick";
    human1.occupation = "scientist";
    human1.age = 70;

    human1.eat();
    
    return 0;
}
```