### Constructors
- Special member function of a class used to initialize objects of this class type.
- Same name as the class with no return type (not even void).
- Instance automatically calls constructor.
```c++
class MyClass {
public:
    MyClass() {    // This is the constructor declaration
        // Constructor's body: you can initialize the object here
    }
};
```
1. **Default Constructors**: Without a user-defined constructor, compiler implicitly declares a constructor `A::A()`.
2. **Parameterized Constructors**: Has parameters.
3. **Copy Constructors**: Initialize new object as a copy of an existing object.
4. **Move Constructors**: Initialize a new object from an existing object's resources, transforming the source object in the process.