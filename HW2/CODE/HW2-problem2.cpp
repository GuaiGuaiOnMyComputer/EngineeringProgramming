#include <iostream>
#include <cmath>

double getSurfaceArea(double _radius, double _height)
{
    const double pi = 3.14159;
    return 2*pi*_radius*_height + 2*pow(_radius, 2)*pi;
}

int main()
{
    double radius, height;
    std::cout << "Student B10831020" << std::endl;
    std::cout << "Calculate the surface area of a cylinder" << std::endl;
    std::cout << "Please enter the radius of the cylinder \t";
    std::cin >> radius;
    std::cout << "Please enter the height of the cylinder \t";
    std::cin >> height;
    std::cout << "\tThe surface area of this cylinder is " << getSurfaceArea(radius, height) << std::endl;
    system("pause");
    return 0;
}