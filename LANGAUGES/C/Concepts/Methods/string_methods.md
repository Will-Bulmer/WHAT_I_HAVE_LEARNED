## Useful String Methods

```cpp
#include <iostream>

int main() {
    std::string name;

    std::cout << "Enter your name: ";
    std::getline(std::cin, name); // Input might have spaces

    name.length(); 
    name.empty(); // Boolean value
    name.clear();
    name.append("@gmail.com");
    name.at(0); // First character
    name.insert(0, "@"); // Beginning of string
    name.find(' '); // Finds white space
    name.erase(0 ,3); // [0,3)

    return 0;
}
```