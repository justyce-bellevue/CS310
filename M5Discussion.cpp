#include <iostream>




int main()
{
    float radius;

    std::cout << "Enter the radius of the circle.";
    std::cin >> radius;

    float area = circleArea(radius);

    std::cout << "The area of the circle is " << area << ".";

    return 0;
}

int circleArea(float radius)
{
    float pi = 3.1415;

    float area = pi * radius * radius;

    return area;
}
