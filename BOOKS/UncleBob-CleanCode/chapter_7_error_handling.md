## Error Handling

### 1. Use Exceptions Rather Than Return Codes
- **Old**: Checking for errors immediately after each function call which clutters.
- **New**: Error occurs, an exception is thrown and can be `caught` and handled separately from the main logic.

### 2. Write Your Try-Catch-Finally Statement First
- Exceptions `define a scope` within program. - `Try` code can abort at any time and then resume at the `catch`.
- This is key in `TDD`. You design the code around the errors that are thrown rather than as an afterthought. - - Write tests that `force exceptions` to ensure exception handling code is working properly.

### 3. Provide Context with Exceptions
- Informative error messages. Mention operation that failed and the type of failure.

### 4. Define the Normal Flow
- Exception can clutter the logic. Solve with  `SPECIAL CASE PATTERN [Fowler].`: Treat special cases like they were normal cases so you don't have to keep checking if you have a special case.
*In python:*
```python
class NormalCustomer:
    def __init__(self, name):
        self.name = name

    def getName(self):
        return self.name

class GuestCustomer:
    def getName(self):
        return "Guest"

def getCustomer(name):
    if database.contains(name):
        return NormalCustomer(name)
    else:
        return GuestCustomer()

# Usage:
customer = getCustomer("Bob")
print(customer.getName())  # If "Bob" isn't in the database, it prints "Guest"
```
 -`GuestCustomer` is a special case that prevents the need for null checks or error handling when a customer isn't found.
 - Special case and regular case share a `common interface`.

 ### 5. Don't Return Null
 - Null checks are bad practice as they are easy to forget and can lead to `NullPointerExceptions`.
 **Throw an Excpetion:** Such as `ItemNotFoundException`.
 **Return a Special Case Object:** Could return `EmptyItem` for a method that is supposed to return an item.

 ### 6. Don't Pass Null
 - Hard to deal with `null` that is passed by a caller accidentally. Should forbid passing `null` by default.
 
 The following is good documentation but doesn't solve the problem:
 ```c++
 public class MetricsCalculator
{
 public double xProjection(Point p1, Point p2) {
 assert p1 != null : "p1 should not be null";
 assert p2 != null : "p2 should not be null";
 return (p2.x – p1.x) * 1.5;
 }
}
 ```