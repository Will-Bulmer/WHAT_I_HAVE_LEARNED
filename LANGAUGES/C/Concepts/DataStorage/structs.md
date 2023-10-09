## Struct

- Struct - A structure that groups related variables under one name.
- Structs can contain many different data types.
- Variables in a struct as known as **members**.
- Members can be accessedd with **.** "Class Member Access Operator".

### Structs VS Classess

1. Default Access Specifier:
- Classes have a default access specifier as `private`.
- Structs have a default access specifier as `public`.
2. Inheritance:
- When inheriting from a struct, the default inheritance mode is `public`.
- When inheriting from a class, the default inheritance mode is `private`.
3. Usage Convention
- Conventionally, `structs` are used to group data without too much emphasis on the associated behaviors (methods)
- `Classes` are used when you want to encapsulate data and behaviors together, emphasizing object-oriented principles like inheritance, polymorphism, and encapsulation.

```cpp
#include <iostream>

struct student{
    std::string name;
    double gpa;
    bool enrolled;
};

int main(){

    student student1;
    student1.name = "Spongebob";
    student1.gpa = 3.2;
    student1.enrolled = true;

    return 0;
}
```

## Casting Struct to a Function

```cpp
#include <iostream>

struct Car{
    std::string model;
    int year;
    std::string color;
}

void printCar(Car car);

int main() {
    Car car1;
    Car car2;

    car1.model = "Mustang";
    car1.year = 2023;
    car1.color = "red";

    car2.model = "Corvette";
    car2.year = 2024;
    car2.color = "blue";

    printCar(car1);
    return 0;
}

// CAST BY VALUE
void printCar(Car car){
    std::cout << car.model << '\n';
    std::cout << car.year << '\n';
    std::cout << car.color << '\n';
}

// CAST BY REFERENCE
void printCar(Car &car){
    std::cout << car.model << '\n';
    std::cout << car.year << '\n';
    std::cout << car.color << '\n';
}
```