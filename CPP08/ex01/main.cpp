#include "Span.hpp"

int main()
{
    int	           set[100000];
    int            i = -1;

    while (++i < 100000)
        set[i] = i + -50000;
    /*
        init set with range (-50000 - 49999) so the longest span is 99999 and shortest span 1
    */
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
        std::cout << "shortest span for sp: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span for sp: " << sp.longestSpan() << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "-------------------------------\n"; 

    sp.addNumbers(subspan);
    try
    {
        std::cout << "shortest span for sp: " << sp.shortestSpan() << std::endl;
        std::cout << "longest span for sp: " << sp.longestSpan() << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "-------------------------------\n"; 
    std::cout << "-------------------------------\n"; 

    Span subSp = Span(0);
    subSp.addNumbers(subspan);
    try
    {
        std::cout << "shortest span for subSp: " << subSp.shortestSpan() << std::endl;
        std::cout << "longest span for subSp: " << subSp.longestSpan() << std::endl;
    }
    catch(const char* e)
    {
        std::cerr << e << '\n';
    }
    std::cout << "-------------------------------\n"; 

    return 0;
}