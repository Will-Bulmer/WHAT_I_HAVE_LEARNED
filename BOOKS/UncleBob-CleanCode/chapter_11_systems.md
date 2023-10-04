## Systems

### 1. Separate Constructing a System from Using it
**Separation of concerns (SoC):** Have Function Level, Class Level, Component Level Service Level, Layer Level.

### 2. Separation of Main
- Moved all aspects of construction to `main`.
- `main` function builds the objects for the system, then passes them to the application.

### 3. Factories
**ABSTRACT FACTORY pattern:** Creational design pattern that encapsulates a group of individual factories that have a common theme without specifying their concrete classes. 

Ie `UIThemeFactory` as the abstract with `DarkThemeFactory` and `LightThemeFactory` as the concretes.

### 4. Dependency Injection
- Used to separate construction from use. 

**Inversion of Control (IoC):** Acts as an assistant `IoC container` which provides the things you need, `dependencies`. Objects control is transferred to a container.
- **Inversion Control** moves secondary responsiblities from an object to other objects that are dedicated to the purpose, so supporting `Single Responsiblity Principle`.

**Dependency Managment:** Object should not take responsibility for instantiating dependecies itself. Should pass it to another "authoritative" mechanism, thereby inverting control.

*In python:*
```python
class Client:
    def __init__(self, service):
        self.service = service

    def perform_task(self):
        self.service.do_something()


class Service:
    def do_something(self):
        print("I'm doing something...")


# Now we create a service
s = Service()

# And inject it into a Client
client = Client(s)

# When we ask the client to perform a task, it uses the injected service
client.perform_task()
```
Instead of `Client` creating an instance of `Service` itself (which would mean it's responsile for managing that depending), we create the service outside of `Client` and inject it into `Client` when we create a `Client` instance.

This is what it would look like without IoC:
*In python:*
```python
class Client:
    def __init__(self):
        self.service = Service()  # Client is instantiating its own dependency

    def perform_task(self):
        self.service.do_something()
```
Where `Client` would have to know about how to create `Service`, when to create it, how to manage its lifecycle, and so on.

### -- JAVA SECTIONS OMITTED --
