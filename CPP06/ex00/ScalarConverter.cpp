#include "ScalarConverter.hpp"
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <climits>

ScalarConverter::~ScalarConverter()
{
}

static bool isImpossible(std::string value)
{
    if (value[0] == '-' || value[0] == '+')
        value.erase(0, 1);
    if (value.find_first_of('.') != value.find_last_of('.'))
        return (true);
    if (value[value.size() - 1] == '.')
        return (true);
    for (size_t i = 0; i < value.size(); i++)
        if (!isdigit(value[i]) && value[i] != '.')
            return (true);
    return (false);
}

static bool isChar(std::string value)
{
    if (value.size() == 1 && isprint(value[0]) && !isdigit(value[0]))
        return (true);
    return (false);
}
static enum pseudo_literal isNan(std::string &value, bool &_isChar)
{

    if (value == "nan" || value == "nanf")
        return (Nan);
    else if (value == "inf" || value == "+inff" || value == "+inf")
        return (Inf_p);
    else if (value == "-inff" || value == "-inf")
        return (Inf_n);
    if ((_isChar = isChar(value)))
        return (CHAR);
    if (!_isChar && value[value.size() - 1] == 'f')
        value.erase(value.size() - 1, value.size() - 1);
    if (isImpossible(value))
        return (Impossible);
    return (Normal);
}

static void    print(long i, float f, double d)
{
    if (i > INT_MAX || i < INT_MIN)
        std::cout << "int\t: impossible" << std::endl;
    else
        std::cout << "int\t: " <<  static_cast<int>(i) << std::endl;
    if ((f == static_cast<long>(f)) && f < 1000000) {
        std::cout << "float\t: " << f << ".0f" << std::endl;
        std::cout << "double\t: " << d << ".0" << std::endl;
    }
    else
    {
        std::cout << "float\t: " << f << "f" << std::endl;
        std::cout << "double\t: " << d << std::endl;
    }
}
static void ConvertEntry(std::string& value, bool _isChar)
{
    double  d;
    float   f;
    long    l;

    if (!_isChar)
    {
        l = atol(value.c_str());
        d = atof(value.c_str());
        f = static_cast<float>(d);
        if (l >= 32 && l <= 126)
            std::cout << "char\t: " << static_cast<char>(l) << std::endl;
        else
            std::cout << "char\t: Non displayable" << std::endl;
    }
    else
    {
        l = static_cast<int>(value[0]);
        d = static_cast<double>(value[0]);
        f = static_cast<float>(value[0]);
        std::cout << "char\t: " << value[0] << std::endl;
    }
    print(l, f, d);
}

void ScalarConverter::convert(std::string& value)
{
    bool _isChar;
    enum pseudo_literal pseudo;

    pseudo = isNan(value, _isChar);
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
        default :
            ConvertEntry(value, _isChar);
            break;
    }
}
