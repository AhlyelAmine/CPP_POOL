#include "iter.hpp"

int main()
{
    int integers[5] = {1, 2, 3, 4, 5};
    char chars[5] = {'a', 'b', 'c', 'd', 'e'};

    std::cout << "Integers : \n";
    iter(integers, 5, print<int>);
    std::cout << "\nIntegers * 10 : \n";
    iter(integers, 5, mult10<int>);
    iter(integers, 5, print<int>);
    std::cout << "\nchars : \n";
    iter(chars, 5, print<char>);
    std::cout << "\nchars + 1 : \n";
    iter(chars, 5, inc<char>);
    iter(chars, 5, print<char>);
    std::cout << "\n";
    return 0;
}
