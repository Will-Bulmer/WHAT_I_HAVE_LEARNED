## Memory Address

- memory address = a location in memory where data is stored
- A memory address can be accessed with **&** (address-of operator)

A variable is a container for some data. This data exists somewhere in the computers memory. 

```cpp
#include <iostream>

int main() {
    std::string name = "Bro";
    int age = 21;
    bool student = true;

    std::cout << &name; // Memory address of name variable (4 bytes)

    return 0;
}
```

## Cast by Value VS Cast by Reference

```cpp
#include <iostream>

void swap(std::string x, std::string y);
int main(){
    std::string x = "Kool-Aid";
    std::string y = "Water";
    std::string temp;

    swap(x, y);

    std::cout << "X: " << x << '\n';
    std::cout << "X: " << x << '\n';

    return 0;
}

// PASS BY VALUE (makes copies)
void swap(std::string x, std::string y){
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}

// PASS BY REFERENCE
void swap(std::string &x, std::string &y){
    std::string temp;
    temp = x;
    x = y;
    y = temp;
}
```

## Pointers
- pointers = variable that stores a memory address of another variable
- Sometimes it's easier to work with an address
  - **&** : address-of operator
  - \* : dereference operator 

```cpp
#include <iostream>

int main(){

    std::string name = "Bro";
    std::string *pName = &name;

    std::cout << *pName;

    return 0;
}
```