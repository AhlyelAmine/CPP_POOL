#include "RPN.hpp"
#include <sstream>

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        RPN rpn;
        rpn.rpnCalcul(argv[1]);  
    }
    else
        std::cerr << "Error\n";
    return 0;
}
