#include "Point.hpp"

int main()
{
    std::string result =  bsp(Point(-2.0f, 1.0f), Point(3.0f, 2.0f), Point(1.0f, 5.0f), Point(-1.0f, 2.15f)) ? "the point is inside the triangle" : "the point isn't inside the triangle";
    std::cout << result << std::endl;
}