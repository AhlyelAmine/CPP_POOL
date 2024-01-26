#include "ScalarConverter.hpp"

int main(int ac, char **av)
{
    while (--ac)
    {
        double b = -45454561561654165165454542444554545455.595458484865455465465165151651;
        float c =  -45454561561654165165454542444554545455.595458484865455465465165151651;
        // int d =    -45454561561654165165454542444554545455.595458484865455465465165151651;
        // c = -__FLT_HAS_INFINITY__;
        std::string a = av[ac];
        std::cout << (b) << std::endl;
        std::cout << (c) << std::endl;
        // std::cout << (d) << std::endl;
        ScalarConverter::convert(a);
    }
}
