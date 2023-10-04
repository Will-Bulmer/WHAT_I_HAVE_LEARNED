## Classes

### 1. Class Organization
- **`list of variables`**. In order of importance:
1. Public static constants
2. Private static variables
3. Private instance variables
4. Public Functios
5. Private Utilities

### 2. Classes Should Be Small
- Functions measured by lines
- Classes measured by `responsibilities`. Concise name or it has too many.

### 3. The Single Responsibility Princple (SRP)
- Class or module should have one, and only one, `reason to change`.  
- Many small classes rather than a few large ones.

### 4. Cohesion
- Classes should have a small number of `instance variables`. Each method should manipulate one or more of those variables.
- **Maximally cohesive** class has each variable used by each method.
- Want `high cohesion`.

### 5. Maintaining Cohesion Results in Many Small Classes
- When classes lose cohesion, split them.

### 6. Organizing for Change
Violates SRP:
*In Java:*
```java
public class Sql {
 public Sql(String table, Column[] columns)
 public String create()
 public String selectAll()
}
 ```
 For easier maintence, should split into subclasses:
 *In Java:*
 ```java
 abstract public class Sql {
 public Sql(String table, Column[] columns)
 abstract public String generate();
}
public class CreateSql extends Sql {
 public CreateSql(String table, Column[] columns)
 @Override public String generate()
}
public class SelectSql extends Sql {
 public SelectSql(String table, Column[] columns)
 @Override public String generate()
}
 ```
 Reduces risk that one functioning breaking then breaks the rest. This obeys **`Open-Closed Principle`** where classes should be open for extension but closed for modification.

 ### 7. Isolating from Change
 - Decouple systems by creating `interfaces`. Ie. Some tests might have asserts that change every 5mins. You need to create an interface to cope with this.
