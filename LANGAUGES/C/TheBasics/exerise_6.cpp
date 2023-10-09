/*
PROBLEM: Write a program for rolling a dice.
Hint: [rand() % (maxValue - minValue + 1)] + minValue
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

int dice_roll(){
    srand(time(nullptr));
    //int result = rand() % 6; // 0 can't be a value
    int minValue = 1;
    int maxValue = 6;
    int result = rand() % (maxValue - minValue + 1) + minValue;
    return result;
}

int main(){
    std::cout << dice_roll() << std::endl;
    return 0;
}