#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP
#include <iostream>

class ScalarConverter
{
    ScalarConverter();
    public :
        ~ScalarConverter();
        static void convert(std::string& value);
};

#endif