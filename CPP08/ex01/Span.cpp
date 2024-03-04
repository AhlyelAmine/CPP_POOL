#include "Span.hpp"
#include <algorithm>

Span::Span(unsigned int n) : maxSize(n)
{
}

Span::Span(Span const &span)
{
    *this = span;
}

Span &Span::operator=(Span const &span)
{
    maxSize = span.maxSize;
    return (*this);
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (this->span.size() < this->maxSize)
        this->span.push_back(n);
    else
        throw "Span is full\n";
}

int Span::shortestSpan()
{
    if (this->span.size() < 2)
        throw "span size is too short\n";
    std::sort(this->span.begin(), this->span.end());
    int shortpath = this->span[1] - this->span[0];
    for (size_t i = 1; i < this->span.size() - 1; i++)
    {
        if (this->span[i + 1] - this->span[i] < shortpath)
            shortpath = this->span[i + 1] - this->span[i];
    }
    return (shortpath);
}

int Span::longestSpan()
{
    if (this->span.size() < 2)
        throw "span size is too short\n";
    std::sort(this->span.begin(), this->span.end());
    int longpath = this->span.back() - this->span[0];
    for (size_t i = 1; i < this->span.size() - 1; i++)
    {
        if (this->span.back() - this->span[i] > longpath)
            longpath = this->span.back() - this->span[i];
    }
    return (longpath);
}

void Span::addNumbers(std::vector<int> subspan)
{
    this->span.insert(span.end(), subspan.begin(), subspan.end());
}
