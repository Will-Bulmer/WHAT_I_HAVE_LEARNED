### Complexity and Big O Notation

**Complexity** of an algorithm is a measure of the amount of time and/or space required by an algorithm for an input of a given sizze e.g. `N`. Unless otherwise stated, the term *complexity* always refers to the worst-case complexity.

For linear search:
1. The **time complexity** / **running time** of an algorithm is `cN`, for some fixed constant `c` that depends on the number of operations we perform in each iteration and the time taken to execute a statement.
2. The **space complexity** is some constant `c'` independent of `N`, since we just need a single variable `position` to iterate through the array, and it occupies a constant space in the computer's memory (RAM).

**Big O Notation**: Worst-case complexity is often expressed using the Big O notation. In Big 0, we drop fixed constants and lower power of variables to capture the trend of relationship between the size of the input and the complexity of the algorithm i.e if the complexity of the algorithm is `cN^3 + dN^2 + eN + f`, then we called it **`O(N^3)`**

For linear search:
1. Time complexity is **O(N)** and its space complexity is **O(1)**