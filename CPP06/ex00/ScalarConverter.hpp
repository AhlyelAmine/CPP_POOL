#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

# include <iostream>

enum pseudo_literal 
{
    Normal,
    Nan,
    Inf_p,
    Inf_n,
    Impossible,
    CHAR
};

class ScalarConverter
{
    ScalarConverter();
    public :
        ~ScalarConverter();
        static void convert(std::string& value);
};

#endif
