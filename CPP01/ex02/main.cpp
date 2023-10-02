#include <iostream>

int main()
{
    std::string var = "HI THIS IS BRAIN";

    std::string *stringPTR = &var;
    std::string &stringREF = var;

    std::cout << &var << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;

    std::cout << var << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}