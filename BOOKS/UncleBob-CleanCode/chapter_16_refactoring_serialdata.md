## Refactoring *SerialDate*

This is library in Java. A professional review was done on it

### 1. First, Make it Work
- Using **Clover**, can see what unit tests cover.

### 2. Then Make It Right
- `SerialDate` class implies *implementation*. Abstract so should be `DayDate`.
- Class `MonthConstants` should be an *enum*. Enum is a special class that defines a bunch of CONSTANTS.
- Base classes knowing about their derivatives is bad. Use *ABSTRACT FACTORY, SINGLETON, DECORATOR*.
- **Explaining Temporary Variables:** Temporary Variables are used in methods to store interim values, can make code harder to read. Instead, replace with well-named methods.
*Ie, in C++:*
```c++
double price() {
    int quantity = // ... some value
    double itemPrice = // ... some value
    // Temporary variable for the discount
    double discountFactor;
    if (quantity > 100) 
        discountFactor = 0.85;
    else 
        discountFactor = 0.95;
    return quantity * itemPrice * discountFactor;
}
```
After:
```c++
double discountFactor() {
    int quantity = // ... some value
    if (quantity > 100)
        return 0.85;
    else
        return 0.95;
}

double price() {
    int quantity = // ... some value
    double itemPrice = // ... some value
    return quantity * itemPrice * discountFactor();
}
```
Temporary variable 'discountFactor' replaced by a method called 'discountFactor()'