## Functions

### 1. Small
- Think 4-5 lines of code!

### 2. Blocks and Indenting
- Indent level of functions should not be greater than 2
- `If`, `While` and `else` statments should really be one line long as they should be a function call.

### 3. Do One Thing
- A function does more then one thing if you can extract another function from it with a name that is merely a restatement of its implementation.

### 4. One Level Of Abstraction Per Function 
- Make sure the statements within our functions are all at the same level of abstraction. Ie getHTML is a high level of abstraction whereas .append("\n") is a low level of abstraction. Mixing levels of abstraction is always confusing.

### 5. Reading Code From Top to Bottom: The Stepdown Rule
- Every function should be followed by those that are at the next level of abstraction. Each function introduces the next. Ie
```python
def cook_dinner():
    prepare_ingredients()
    cook_meal()
    serve_dinner()

def prepare_ingredients():
    # code to prepare ingredients

def cook_meal():
    # code to cook the meal

def serve_dinner():
    # code to serve the dinner
```

### 6. Switch Statement
- They always do N things and cannot be one line. Best thing is to bury a switch in a low level class and to never repeat it. One way to do this is with `polymorphism`.
This is where we allow objects of different types to be treated as objects of a base type. 
- `Inheritance polymorphism` - Allows child class to be treated as parent class
- `Overloaded polymorphism` - Functions that have the same name but different parameters.
```python
class Animal:
    def make_sound(self):
        pass

class Dog(Animal):
    def make_sound(self):
        return "Woof!"

class Cat(Animal):
    def make_sound(self):
        return "Meow!"

# Function that can operate on any object of type Animal.
# This includes subclasses like Dog, Cat
# Passing Dog and Cat will call the correct make_sound
def animal_sound(animal: Animal):
    return animal.make_sound()

dog = Dog()
cat = Cat()

print(animal_sound(dog))  # Outputs: Woof!
print(animal_sound(cat))  # Outputs: Meow!
```

- Now consider this function.
```c++
public Money calculatePay(Employee e)
throws InvalidEmployeeType {
 switch (e.type) {
 case COMMISSIONED:
 return calculateCommissionedPay(e);
 case HOURLY:
 return calculateHourlyPay(e);
 case SALARIED:
 return calculateSalariedPay(e);
 default:
 throw new InvalidEmployeeType(e.type);
 }
 }
```
- It is large and will grow when new employee types are added
- Does more than one thing
- Violates `SRP' and 'OCP'.
- Unlimited amount of functions with the same structure
Should bury the `switch` statement in the basement of an `ABSTRACT FACTORY` and never let anyone see it.

```c++
public abstract class Employee {
 public abstract boolean isPayday();
 public abstract Money calculatePay();
 public abstract void deliverPay(Money pay);
}
-----------------
public interface EmployeeFactory {
 public Employee makeEmployee(EmployeeRecord r) throws InvalidEmployeeType;
}
-----------------
public class EmployeeFactoryImpl implements EmployeeFactory {
 public Employee makeEmployee(EmployeeRecord r) throws InvalidEmployeeType {
 switch (r.type) {
 case COMMISSIONED:
 return new CommissionedEmployee(r) ;
 case HOURLY:
 return new HourlyEmployee(r);
 case SALARIED:
 return new SalariedEmploye(r);
 default:
 throw new InvalidEmployeeType(r.type);
 }
 }
}
```
Factory uses switch statements to create appropriate instances of the derivates of Employee, and the various functions are dispatched `polymorphically` through the `Employee` interface.

### 7. Function Arguments
- Ideal number is zero.
- Ie, `StringBuffer` could be passed as an `argument` rather than an `instance variable`. Would require interpretation every time you see it. Arguments at a different level of abstraction to the function are bad.
- Testing with all combinations of arguments are challenging.

### 8. Common Monadic Forms
- Asking questions about an argument such as `boolean fileExists("MyFile")`
- Operating and transforming and returning such as `InputStream fileOpen("MyFile")`
- An event such as `void passwordAttemptFailedNtimes(int attempts)`

### 9. Flag Arguments
- Passing a boolean into a function is BAD. Complicates the signature of the method and does more than one thing.

### 10. Dyadic Functions
- `writeField(name)` easier to understand than `writeField(output-Steam, name)`. Second one requires a pause to realise the first parameter is to be ignored.
- Reasonable is `Point p = new Point(0,0)` since the two arguments are *ordered components of a single value*.
- `assertEquals(expected, actual)` are problematic due to ordering convention.

### 11. Argument Objects
- More than two or three arguments, some of them should be wrapped in a class of their own.
```c++
Circle makeCircle(double x, double y, double radius);
Circle makeCircle(Point center, double radius);
```
- Groups of variables passed together are likely part of a concept and deserve a name

### 12. Argument Lists
- If variables arguments are all treated identically,, they are equivalent to a single argument of type `List`.
```c++
String.format("%s worked %.2f hours.", name, hours);
public String format(String format, Object... args)
```

### 13. Verbs and Keywords
-Function and argument should form a nice `verb/noun pair`. Like `write(name)`.
- `writeField(name)` uses the `keyword` form of a function name. Encode argument names into the function name. Ie. `assertExpectedEqualsActual(expected, actual)` better than `assertEquals`.

### 14. Have No Side Effects
- Ie. checkPassword has the hidden Session.initialize() which creates a `temporal coupling`. Can only checkPassword at certain times (when it is safe to initialize the session).

### 15. Output Arugments
- Ie. `appendFooter(s)`. Does it append s to the footer? Does it append footer to s? Is s an input or output? Should be `report.appendFooter();`.

### 16. Command Query Separation
- Functions should do something or answer something, but NOT both. Ie. `if (set("username", "unclebob"))...` is not clear if setting username was successful, or if it was previously set. Should separate.

### 17. Prefer Exceptions to Returning Error Codes
- Returning error code like `if (deletePage(page) == E_OK)` must be dealt with immediately. Can separate error processing code from happy path code:
```c++
try {
deletePage(page);
registry.deleteReference(page.name);
configKeys.deleteKey(page.name.makeKey());
}
catch (Exception e) {
logger.log(e.getMessage());
}
```

### 18. Extract Try/Catch Blocks
- `Try/catch` mixes error processing with normal processing. 

### 19. Error Handling Is One Thing
- If `try` exists in the function, it should be the first word and nothing after `catch/finally` blocks.

### 20. The Error.java Dependency Magnet
- Returning erro codes usually implies that there is some class or enum in which all error codes are defined called `dependency magnet`. When `Error enum` changes, all other classes must be recompiled and redeployed which puts negative pressure. Exceptions are better.

### 21. Writing Functions
- Begin with drafts and then refine to follow the rules.


