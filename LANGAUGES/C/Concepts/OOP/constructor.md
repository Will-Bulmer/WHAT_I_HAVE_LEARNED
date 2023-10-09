## Constructor

- **Constructor** is a special method that is *automatically called* when an object is instantiated.
- Useful for assigning values to attributes as arguments.

```cpp
#include <iostream>

class Student{
    public:
        std::string name;
        int age;
        double gpa;

    Student(std::string name, int age, double gpa){
        this->name = name;
        this->age = age;
        this->gpa = gpa;
    }

    // Note: if we use different names, dont need `this`
    Student(std::string x, int y, double z){
        name = x;
        age = y;
        gpa = z;
    }
};

int main() {

    Student student1("Spongebob", 25, 3.2);
    return 0;
}
```