## Singleton 

Ensures that a particular class has only one instance. Provides a way to access its instance from anywhere in the application.

### Singleton: Key Components
1. **Private Constructor**: Make the class constructor private. This ensures no other class can create an instance of it.
2. **Private Static Instance**: This is a private static member that will store our one and only instance of the class.
3. **Public Static Function**: This function will check if we already have an instance of our class. If we don't, it will create one. If we do, it will return the one that exists.

4. Private Constructor: The class should have a private constructor to prevent other classes from instantiating it.
5. Static Member: Contains the instance of the singleton class.
6. Public static method: This method provides access to the singlton instance. It either creates the instance (if not created yet) or returns the existing one.

### Implentations
```cpp
class Singleton {
private:
    static Singleton* instance; // Step 2: Private Static Instance
    Singleton() {}  // Step 1: Private Constructor

public:
    static Singleton* getInstance() { // Step 3: Public Static Function
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// We need to define our static instance outside the class
Singleton* Singleton::instance = nullptr;
```

### Consideration in C++:
- **Thread Safety**: To make the above implentation thread safe, could use mutexes or other synchronzation primatives
- **Memory Deallocation**: Always deallocate a `new`