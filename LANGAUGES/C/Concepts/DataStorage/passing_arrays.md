## Passing Arrays
When we pass an array to a function, it decays to a **pointer**: a memory address to the location of the array, and so we can no longer use the sizeof within the local scope.

```cpp
#include <iostream>

double getTotal(double prices[], int size);

int main() {
    double prices[] = {49.99, 15.05, 75, 9.99};
    int size  = sizeof(prices)/sizeof(prices[0])
    double total = getTotal(prices);

    std::cout << "$" << total;
    return 0;
}

double getTotal(double prices[], int size){
    double total = 0;

    /*
    for(int i = 0; i < sizeof(prices)/sizeof(prices[0]); i++){
        total += prices[i];
    }
    */
   for(int i = 0; i < size; i++){
    total += prices[i];
   }
}
```