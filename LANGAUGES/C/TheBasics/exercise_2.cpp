// Implement the following function:
// z = (x + 10) / 3y

#include <iostream>
double function(float x, float y){
    float z = 0.0;
    z = (x + 10) / (3*y);
    std::cout << z;
    return z;
}

int main() {
    float x = 0.0;
    float y = 0.0;
    function(10,5);
}