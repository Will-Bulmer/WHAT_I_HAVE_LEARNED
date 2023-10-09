/*
PROBLEM: Write a function calculate the area of a circle.
User enters the radius of the circle and it returns its area.
*/

#include <iostream>
#include <cmath>

const float pi = 3.14;

double circle_area(float radius){
    float area = pi * pow(radius, 2.0);
    return area;
}

int main() {
    float radius = 0.0;
    std::cout << "Enter the circle radius: " << std::endl;
    std::cin >> radius;
    std::cout << "Area of circle is :" << circle_area(radius) << std::endl;
    return 0;
}