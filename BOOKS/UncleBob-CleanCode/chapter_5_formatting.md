## Formatting

### 1. Vertical Formatting
- File size, rarely over 200.
- Source file like a newpaper article. High level concepts and algorithms at the top.
- Group of lines is a complete thought, and thoughts are separated by blank lines.
- Concepts closely related should be kept `vertically close` to each other.

### 2. Variable Declarations
- Declared as close to their usage as possible.
- `Local variables` at the top of the functions.
- `Control variables` for loops should be declared within the loop statement.

### 3. Instance Variables
- Java: Declared at the top of the class.
- C++: `Scissors` rule - Put all the instanace variables at the bottom.

### 4. Dependent Functions
- Caller should be above the callee if possible. Should be vertically close.

### 5. Conceptual Affinity
- Groups of functions perform a similar operation or common naming theme.

### 6. Vertical Ordering
- High-level to low-level.

### 7. Horizontal Formatting
- Short lines preferred (<120).
- Assignment operators with white space to accentuate.

### 8. Team Rules
- Uusally would decide and encode rules into code formatter of the IDE as a team.