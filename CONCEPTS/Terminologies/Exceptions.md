### Exceptions
**Exception:** Event that occurs during execution that disrupts the normal flow of the program's instructions.
**Exception Object:** Error occurs in a method, method creates an objects and hands it off to the runtime system.
**Try:** Any code that might potentially throw an exception.
**Catch:** Code to handle the exception
**Finally:** Code to be executed regardless of the exception.

Exceptions are meant for `exceptional situations`. Should not be used as a form of flow control in your code.
Bad practice to catch all exceptions. Only catch the exceptions you expect.