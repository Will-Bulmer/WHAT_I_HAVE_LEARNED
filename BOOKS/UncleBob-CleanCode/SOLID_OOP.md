# SOLID Principles

## 1. Single Responsibility Principle (SRP)
>A class should only have one responsiblity or job

### Violation of SRP:
*In python:*
```python
class User:
    def __init__(self, name: str):
        self.name = name

    def get_name(self) -> str:
        return self.name

    def save_user(self) -> None:
        pass  # code to save user details to a database
```
'User' class is handling both user-related operations and data persistence.

### Following SRP:
*In python:*
```python
class User:
    def __init__(self, name: str):
        self.name = name

    def get_name(self) -> str:
        return self.name


class UserDB:
    def save_user(self, user: User) -> None:
        pass  # code to save user details to a database
```
Responsibilites are separated into two classes: 'User' for user-related operations and 'UserDB' for data persistence.

## 2. Open/Closed Principle (OCP)
>Software entities should be open for extension, but closed for modification

### Violation of OCP:
*In python:*
```python
class Rectangle:
    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height

class AreaCalculator:
    def calculate(self, rectangle: Rectangle):
        return rectangle.width * rectangle.height
```
If we wanted to add more shapes to 'AreaCalculator', we would need to modify it, which violates the OCP

### Following OCP:
*In python:*
```python
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Rectangle(Shape):
    def __init__(self, width: int, height: int):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

class Circle(Shape):
    def __init__(self, radius: int):
        self.radius = radius

    def area(self):
        return 3.14 * (self.radius**2)

class AreaCalculator:
    def calculate(self, shape: Shape):
        return shape.area()
```
Are able to add more shapes without changing the 'AreaCalculator' class

## 3. Liskov Substitution Principle (LSP)
>Subtypes must be substitutable for their base types

## Violation of LSP:
*In python:*
```python
class Bird:
    def fly(self):
        pass

class Ostrich(Bird):
    def fly(self):
        raise Exception("Ostrich can't fly")
```
'Ostrich' is a subtype of 'Bird', but it's can't be subsituted in place of 'Bird' without causing issues (since it can't fly).

## Following LSP:
*In python:*
```python
class Bird:
    def fly(self):
        pass

class FlightlessBird(Bird):
    def fly(self):
        raise Exception("Flightless birds can't fly")

class Ostrich(FlightlessBird):
    pass
```
Can substitute 'Ostrich' for 'FlightlessBird' without problems here.

## 4. Interface Segregation Principle (ISP)
>Clients should not be forced to depend upon interfaces they do not use

### Violation of ISP:
*In python:*
```python
class Worker:
    def work(self):
        pass

    def eat(self):
        pass
```
A class that needs the 'work' method will still need to implement or handle the 'eat' method

### Following ISP:
*In python:*
```python
class Workable(ABC):
    @abstractmethod
    def work(self):
        pass

class Eatable(ABC):
    @abstractmethod
    def eat(self):
        pass

class Worker(Workable, Eatable):
    def work(self):
        pass

    def eat(self):
        pass
```
Separated the capabilities into two separate interfaces, 'Workable' and 'Eatable'. Class can choose to implement only the interfaces it needs.

## 5. Dependency Inversion Princple (DIP)
>High-level modules should not depend on low-level modules. Both should depend on abstractions.

### Violation of DIP:
*In python:*
```python
class LightBulb:
    def turn_on(self):
        pass

class ElectricPowerSwitch:
    def __init__(self, light_bulb: LightBulb):
        self.light_bulb = light_bulb

    def press(self):
        self.light_bulb.turn_on()
```
High-level module 'ElectricPowerSwitch' is dependent on the low-level 'LightBulb'.

### Following DIP:
*In python:*
```python
class Switchable(ABC):
    @abstractmethod
    def turn_on(self):
        pass

class LightBulb(Switchable):
    def turn_on(self):
        pass

class ElectricPowerSwitch:
    def __init__(self, device: Switchable):
        self.device = device

    def press(self):
        self.device.turn_on()
```
'ElectricPowerSwitch' and 'LightBulb' depend on the 'Switchable' abstraction. Can switch out the 'LightBulb' with any other 'Switchable' device.

## Abstract Method
Part of the abc (abstract base classes) module. Abstract method is a method that is declared but contains no implementation.
The decorator denotes that the method must be overridden in any concrete (non-abstract) child class.
Useful when you have large set of subclasses that all have the same method signature. Ensures consistency across implementations.
Can reduce duplication due to inheritance.