#ifndef SPAN_HPP
# define SPAN_HPP
#include <iostream>
#include <vector>

#include <stack>
class Span
{
    unsigned int maxSize;
    std::vector<int> span;
    Span();

    public :

        Span(unsigned int);
        Span(Span const &);
        Span &operator=(Span const &);
        ~Span();
        void addNumber(int);
        int shortestSpan();
        int longestSpan();
        void addNumbers(std::vector<int>);
};

#endif
