#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <cmath>

ScalarConverter::~ScalarConverter()
{
}

char char_convert(int value)
{
    return (static_cast<char>(value));
}
enum pseudo_literal 
{
    Normal,
    Nan,
    Inf_p,
    Inf_n,
    Impossible,
    CHAR
};

bool isImpossible(std::string value)
{
    if (value[0] == '-' || value[0] == '+')
        value.erase(0, 1);
    if (value.find_first_of('.') != value.find_last_of('.'))
        return (true);
    for (size_t i = 0; i < value.size(); i++)
        if (!isdigit(value[i]) && value[i] != '.')
            return (true);
    return (false);
}
enum pseudo_literal isNan(const std::string value)
{
    if (value == "nan")
        return (Nan);
    else if (value == "inf" || value == "+inf")
        return (Inf_p);
    else if (value == "-inf")
        return (Inf_n);
    else if (isChar(value))
        return (CHAR);
    else if (isImpossible(value))
        return (Impossible);
    return (Normal);
}


void nanEntry(enum pseudo_literal pseudo)
{
    switch (pseudo)
    {

        case Normal :
            break;
    }
}

// int ft_atoi(std::string value, bool fraction)
// {
//     long long result = 0;
//     int sign = 1;
//     if (value[0] == '-' || value[0] == '+') {
//         if (value[0] == '-')
//             sign = -1;
//         value.erase(0, 1);
//     }
//     for (size_t i = 0; i < value.size(); i++)
//     {
//         if (fraction && value[i] == '.')
//             continue;
//         else if (!isdigit(value[i]))
//             break ;

//         result = result * 10 + static_cast<int>(value[i]) - '0';
//     }
//     return (result * sign);
// }
// size_t floatSize(std::string &value)
// {
//     size_t i = 0;
//     for (; i < value.size(); i++)
//     {
//         if (!isdigit(value[i]) && value[i] != '.')
//             break ;
//     }
//     return (i);
// }

// double ft_atod(std::string value)
// {
//     double  result = 0.0;
//     double  sign = 1.0;
//     size_t  i = 0;

//     if (value[0] == '-' || value[0] == '+') {
//         if (value[0] == '-')
//             sign = -1.0;
//         value.erase(0, 1);
//     }
//     for (; i < value.size(); i++)
//     {
//         if (!isdigit(value[i]))
//         {
//             i++;
//             break ;
//         }
//         result = result * 10.0 + value[i] - 48.0;
//     }
//     if (size_t pos =  value.find_first_of('.') != std::string::npos)
//     {
//         for (size_t inc = 1; pos < value.size(); pos++, inc++)
//         {
//             if (!isdigit(value[pos]))
//                 break ;
//             result += (value[i] - 48.0)/ pow(10, inc);
//         }
//     }
//     return (result * sign);
// }

void ConvertEntry(std::string& value)
{
    int     i = static_cast<int>(atol(value.c_str()));
    double  d = atof(value.c_str());
    float   f = static_cast<float>(d);
    char    c = static_cast<char>(i);

    if (c >= 32 && c <= 126)
        std::cout << "char\t: " << c << std::endl;
    else
        std::cout << "char\t: Non displayable" << std::endl;
    std::cout << "int\t: " << i << std::endl;
    if (f == static_cast<int>(f)) {
        std::cout << "float\t: " << static_cast<float>(f) << ".0f" << std::endl;
        std::cout << "double\t: " << d << ".0" << std::endl;
    }
    else
    {
        std::cout << "float\t: " << static_cast<float>(f) << "f" << std::endl;
        std::cout << "double\t: " << d << std::endl;
    }
}

bool isChar(std::string value)
{
    if (value.size() == 1 && !isalpha(value[0]))
        return (true);
    return (false);
}

void ScalarConverter::convert(std::string& value)
{
    bool _isChar = isChar(value);
    if (!_isChar && value[value.size() - 1] == 'f')
    {
        value.erase(value.size() - 1, value.size() - 1);
        std::cout << value << std::endl;
    }
    enum pseudo_literal pseudo = isNan(value);
    switch (pseudo)
    {
        case Nan :
            std::cout << "char\t: impossible\nint\t: impossible\nfloat\t: nanf\ndouble\t: nan\n";
            break;
        case Inf_p :
            std::cout << "char\t: impossible\nint\t: impossible\nfloat\t: +inff\ndouble\t: +inf\n";
            break;
        case Inf_n :
            std::cout << "char\t: impossible\nint\t: impossible\nfloat\t: -inff\ndouble\t: -inf\n";
            break;
        case Impossible :
            std::cout << "char\t: impossible\nint\t: impossible\nfloat\t: impossible\ndouble\t: impossible\n";
            break;
        case CHAR :
            break ;
        default :
            ConvertEntry(value);
            break;
    }
}
