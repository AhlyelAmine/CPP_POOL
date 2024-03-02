#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>

template <typename T>

void iter(T *array, size_t length, void (*f)(T &))
{
    for (size_t i = 0; i < length; i++)
        f(array[i]);
}
template <typename T>

void print(const T& t)
{
    std::cout << t << " ";
}

template <typename T>

void mult10(const T& t)
{
    t = t * 10;
}

template <typename T>

void inc(const T& t)
{
    t = t + 1;
}

#endif
