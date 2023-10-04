## Factory Method

The Factory Method is a design pattern that provides an interface for creating instances of a class , with its subclasses deciding which class to instantiate.

Goal: Creation of objects without specifying the exact class that will be created

### 1. Step to Implement the Factory Method
1. **Abstract Creator**: This contains the abstract factory method, which return an object of the abstract product type.
2. **Concrete Creators**: These are classes that implement the abstract creator. They override the factory method.
3. **Abstract Product**: Interace for objects created by factory method.
4. **Concrete Produces**: Actual objects that the factory methods will produce.

### 2. Simple Factory Method Pattern Implentation
*Step 1: Abstract Product*
```cpp
class Fruit {
public:
    virtual void eat() = 0;  // pure virtual method
};
```

*Step 2: Concrete Product*
```cpp
class Apple : public Fruit {
public:
    void eat() override {
        std::cout << "Eating an apple." << std::endl;
    }
};

class Banana : public Fruit {
public:
    void eat() override {
        std::cout << "Eating a banana." << std::endl;
    }
};
```

*Step 3: Abstract Creator*
```cpp
class FruitFactory {
public:
    virtual Fruit* createFruit() = 0;  // pure virtual method
};
```

*Step 4: Concrete Creators*
```cpp
class AppleFactory : public FruitFactory {
public:
    Fruit* createFruit() override {
        return new Apple();
    }
};

class BananaFactory : public FruitFactory {
public:
    Fruit* createFruit() override {
        return new Banana();
    }
};
```