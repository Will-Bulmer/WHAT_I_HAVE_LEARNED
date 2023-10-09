## Fill function

- fill() = Fills a range of elements with a specified value
           fill(begin, end, value)

```cpp
#include <iostream>

int main(){

    const int SIZE = 100;
    std::string foods[SIZE];

    // Beginning address - foods
    // Ending address - foods + SIZE
    fill(foods, foods + SIZE, "pizza"); 

    return 0;
}
```