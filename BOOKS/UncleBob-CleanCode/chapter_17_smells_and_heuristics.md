## Smells and Heuristics

Uses a lot of Martin Fowler's examples.

### 1. Comments
**C1:Inappropriate Information -** Only technical notes.
**C2:Obselete Comment -** Old, irrevelant, incorrect.
**C3:Redundant Comment -** 
```c++
i++; // increment i
```
**C4:Poorly Written Comment -** Be brief.
**C5:Commented-Out Code**

### 2. Environment
**E2:Tests Requires More Than One Step -** All unit tests must run with one command 

### 3. Functions
**F1: Too Many Arguments**
**F2: Output Arguments -** Counterintuitive.
**F3: Flag Arguments -** Boolean arguments violate SRP.
**F4: Dead Function -** Methods never called are discarded.

### 4. General
**G1: Multiple Langauges in One Source File -** Ideally one langauge.
**G3: Incorrect Behaviour at the Boundaries -** Look for every boundary condition and test for it.
**G5: Duplication -** DRY principle (Don't Repeat Yourself). Repeated switch/case or if/else chains should be replaced with `polymorphism`. For repeated algorithms, use the `TEMPLATE METHODS` where skeleton of algorihtm is a superclass and subclasses can override steps. Can also use `STRATEGY` pattern. This is a beahvioural design pattern that enables an algorithm's behaviour to be selected at runtime.
**G6: Code at Wrong Level of Abstraction -** Higher level concepts in base class and low level in derivatives. Eg. Constants, variables or utility functions that pertain only to the detailed implementation should not be present in the base class.
**G8: Too Much Information -** Limit what is exposed at the interfaces of classes and modules. Few methods a class has, the better. Fewer variables a function knows about the better. The few instance variables a class has, the better. HIDE YOUR DATA. Keep coupling low.
**G9: Dead Code -** Body of an if statement that checks for a condition that can't happen.
**G10: Vertical Separation -** Variables and functions defined close to where they are used. Local variables declared above their first usage, small vertical scope.
**G12: Clutter -** Decoration with no implementation etc.
**G13: Artifical Coupling -** Coupling between two modules that serves no direct purpose.
**G14: Feature Envy -** Methods of a class should interested in the variables and functions of the class they belong to and not other classes.
**G15: Selector Arguments -** Better to have may functions that pass code into a function to select behaviour.
**G18: Inappropriate Static -** 
```c++
Math.max(double a, double b) \\ Good Static Method

HourlyPayCalculator.calculatePay(employee, overtimeRate) \\ Bad Static Method
```
Since we want 'HourlyPayCalculator' to be polymorphic for 'OvertimeHourlyPay'. Function should be a `non static member function` of Employee.
**G19: Use Explanatory Variables -** Break up calculations into intermediate values with descriptive names.
**G23: Prefer Polymorphism to If/Else or Switch/Case -** `ONE SWITCH` rule: *There may be no more than one switch statement for a given type of selection. The cases in that switch statement must create polymorphic objects that take the place of other such switch statements in the rest of the systems.*
*In C++:*
```c++
enum ShapeType {
    circle,
    rectangle,
    triangle
};

class Shape {
public:
    virtual void draw() = 0;
};

void drawShape(ShapeType shapeType) {
    switch(shapeType) {
        case circle:
            // draw a circle
            break;
        case rectangle:
            // draw a rectangle
            break;
        case triangle:
            // draw a triangle
            break;
    }
}
```
Should instead create `polymorphic objects`.
```c++
class Shape {
public:
    virtual void draw() = 0;
};

class Circle : public Shape {
public:
    void draw() override {
        // draw a circle
    }
};

class Rectangle : public Shape {
public:
    void draw() override {
        // draw a rectangle
    }
};

class Triangle : public Shape {
public:
    void draw() override {
        // draw a triangle
    }
};

Shape* createShape(ShapeType shapeType) {
    switch(shapeType) {
        case circle:
            return new Circle();
        case rectangle:
            return new Rectangle();
        case triangle:
            return new Triangle();
        default:
            return nullptr;
    }
}

// Somewhere in your code
ShapeType shapeType = //...
Shape* shape = createShape(shapeType);
if (shape != nullptr) {
    shape->draw();
}
```
Switch method creates the shapes but no more switch statements are needed, right method called thanks to polymorphism.
**G25: Replace Magic Numbers with Named Constants**
**G28: Encapsulate Conditionals -**
For example:
```c++
if (shouldBeDeleted(timer))
```
is preferable to
```c++
if (timer.hasExpired() && !timer.isRecurrent())
```
**G29:Avoid Negative Conditionals -**
For example:
```c++
if (buffer.shouldCompact())
```
is preferable to
```c++
if (!buffer.shouldNotCompact())
```
**G33: Encapsulate Buondary Conditions -** For example 'level + 1' should be 'nextLevel'.
**G36: Avoid Transistive Navigation -** A knows B and B knows C, dont want A knows C - `Law of Demeter`. Modules should only know about their immediate collaborators.

## 5. Names
**N2: Choose Names at the Appropriate Level of Abstraction -** Don't pick names that communicate implementation. Choose names that reflect the level of abstraction.   
```c++
public interface Modem {
 boolean dial(String phoneNumber);
 boolean disconnect();
 boolean send(char c);
 char recv();
 String getConnectedPhoneNumber();
}
```
What if modems aren't connected by dialling. A more appropriate name would be `boolean connect(String connectionLocator)`.
**N5: Use Long Names for Long Scopes -** Length of a name should be related to the length of the scope.
**N7: Names Should Describe Side-Effects -** Function names should describe everything a function does, side effects included.

## 6. Tests
**T1: Insufficient Tests -** Test suite should test everything that could possibly break.
**T2: Use a Coverage Tool -** Reports gaps in testing strategy.
**T3: Don't Skip Trivial Tests**
**T5: Test Boundary Conditions**
**T6: Exhaustively Test Near Bugs**
**T9: Tests Should be Fast**
