## Breaks and Continues

`break` = break out of a loop
`continue` = skip current iteration

```cpp
#include <iostream>

int main() {
    for(int i = 1; i <=20, i++){
        if (i == 13){
            break; // End loop
        }
        if (i == 13){
            continue; // Skip number 13
        }
        std::cout << i << '\n';
    }
    return 0;
}
```