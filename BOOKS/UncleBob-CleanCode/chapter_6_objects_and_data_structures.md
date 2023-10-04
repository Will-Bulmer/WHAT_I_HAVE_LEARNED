## Objects and Data Structures

### 1. Data Abstraction
**Concrete Point**
Exposes Implentation
```c++
public class Point {
 public double x;
 public double y;
}
```
**Abstract Point**
Hides the details of our data.
```c++
public interface Point {
 double getX();
 double getY();
 void setCartesian(double x, double y);
 double getR();
 double getTheta();
 void setPolar(double r, double theta);
}
```

### 2. Data/Object Anti-Symmetry
- **Objects:** `Hide data` behind abstractions and `expose functions` that operate on the data.
- **Data Structures:** `Expose data` and have `no meaningful functions`.

Think of an example of using shapes and functions on them.
- `Procedural Shape` (Using `Data Structures`):
```c++
public class sqaure{
    ...
}
public class Rectangle{
    ...
}
public class geometry{
    //function properties
}
```
Easy to `add functions`. Hard to add new data structures, 

- `Polymorphic Shape` (Object Oriented):
```c++
    public class sqaure implements Shape{
        //init
        public double area(){
            ...
        }
    }
    public class rectangle implements Shape{
        //init
        public double area(){
            ...
        }
    }
```
Easy to `add new classes`. Hard to add new functions.

### 3. The Law of Demeter
- Module should not know about the innards of the `objects` it manipulates. Objects hide their data and expose operations. `Only talk to your immediate friends`.
- Method f of a class C should only call methods of these:
    - C
    - Object created by f.
    - Object passed as an argument to f.
    - Object held in an instance variable of C

**Violation of Law of Demeter**:
```c++
final String outputDir = ctxt.getOptions().getScratchDir().getAbsolutePath();
```
Chain of objects creates tightly coupled code which is bad. Gives knowledge of objects innards.
**Following the Law of Demeter**:
```c++
final String outputDir = ctxt.getOutputDirAbsolutePath();
```
### 4. Data Transfer Objects
- `Data structure` is a class with public variables and no variables sometimes called `data transfer objects` or `DTO`.

### 5. Active Record
- Type of `DTO` with nagivational methods like `save` and `find`.
