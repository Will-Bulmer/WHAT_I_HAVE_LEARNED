/*
Write a program that can convert temperatures from fahrenheit to celcius.
Program should ask its users to enter a temperature in fahrenheit, and then
it will print out to the console, temperature in celcius.
*/

#include <iostream>

void temperature_converter(float fahrenheit){
    float celcius = (fahrenheit - 32.0) * (5.0/9.0);
    std::cout << "In Celcius, this is: " << celcius << std::endl;
}

int main(){
    std::cout << "Please enter a temperature in fahrenheit: " << std::endl;
    float fahrenheit = 0.0;
    std::cin >> fahrenheit;
    temperature_converter(fahrenheit);
    return 0;
}