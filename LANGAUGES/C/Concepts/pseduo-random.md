## Random Number Generator

pseudo-random = NOT truly random (but close)

```cpp
#include <iostream>
#include <ctime>

int main(){
    srand(time(NULL))
    int num = rand(); // Between 0 and 32657
    int num = rand() % 6 // Between 0 through 6
    int num = (rand() % 6) + 1

    std::cout << num;

    return 0;
}
```