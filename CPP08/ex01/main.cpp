#include "Span.hpp"

int main()
{
    int	const           set[]	= { 42, 54, 957, 432, 1234, 0, 754, 16576 };
	size_t const        set_size( sizeof(set) / sizeof(int) );
	std::vector<int>    subspan( set, set + set_size );

    Span sp = Span(5);

    sp.addNumber(3);

    std::cout << "-------------------------------\n"; 
    try
    {
        std::cout << sp.shortestSpan() << std::endl;
        std::cout << sp.longestSpan() << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << "exception : " << e;
    }
    std::cout << "-------------------------------\n"; 

    sp.addNumber(6);
    sp.addNumber(9);
    sp.addNumber(11);
    sp.addNumber(17);

    try
    {
        std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
        std::cout << "longest span : " << sp.longestSpan() << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "-------------------------------\n"; 

    sp.addNumbers(subspan);

    try
    {
        std::cout << "shortest span : " << sp.shortestSpan() << std::endl;
        std::cout << "longest span : " << sp.longestSpan() << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "-------------------------------\n"; 

    return 0;
}