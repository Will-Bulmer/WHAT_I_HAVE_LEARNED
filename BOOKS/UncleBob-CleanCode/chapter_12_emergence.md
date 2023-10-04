## Emergence

### Getting Clean via Emergent Design
A design is "simple" if it follows these rules:
- Runs all the tests
- Contains no duplication
- Expresses the intent of the programmer
- Minimizes the number of classes and methods 

### 1. Simple Design Rule 1: Runs All the Tests
- Easier to test classes that conform to the SRP.
- Tight coupling makes it difficult to write tests.

### 2. Simple Design Rules 2-4: Refactoring
- Incrementally refactoring code each `few line`. Reflect, did we degrade the design?
- Increase cohesion, decrease coupling, separate concerns, modularize system concerns, shrink functions and classes, choose better names etc.

3 Rules of simple design:
1. Eliminate duplication
2. Ensure expressiveness
3. Minimize number of classes and methods

### 3. No Duplication
- Duplication of implementation:

**TEMPLATE METHOD pattern:** Technique for removing higher-level duplication... Defines `skeleton` of an algorithm in a `base class`. Subclasses can override steps without changing its structure.

### 4. Expressive
- Need's to read well to coders without a deep understanding of the problem: `long term maintenance`.
- Good names
- Small functions and classes
- Standard nomenclature. Use standard `patterns` such as **COMMAND** or **VISITOR** in the names of classes that implement those patterns.

### 5. Minimal Classes and Methods
- Don't want too many tiny classes and methods. Need `class count` low.


