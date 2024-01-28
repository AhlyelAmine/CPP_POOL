#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <cmath>

template <typename T>
class Array
{
    T *array;
    unsigned int n;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &copy);
    ~Array();
    Array &operator=(const Array &copy);
    int &operator[](unsigned int i);
    unsigned int size() const;

    class OutOfLimitsException : public std::exception
    {
    public:
        virtual const char *what() const throw();
    };
};

template <typename T>
Array<T>::Array() : array(new T()), n(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), n(n)
{
    for (unsigned int i(0); i < n; i++)
        this->array[i] = i;
}

template <typename T>
Array<T>::Array(const Array &copy) : array(new T[copy.n]), n(copy.n)
{
    for (unsigned int i(0); i < copy.n; i++)
        this->array[i] = copy.array[i];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return this->n;
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &copy)
{
    if (this->array)
        delete[] this->array;
    this->array = new T[copy.n];
    for (unsigned int i(0); i < copy.n; i++)
    {
        this->array[i] = copy.array[i];
    }
}

template <typename T>
int &Array<T>::operator[](unsigned int i)
{
    try
    {
        return this->array[i];
    }
    catch (std::exception &e)
    {
        std::cout << e.what();
    }
}

template <typename T>
Array<T>::~Array()
{
    delete[] this->array;
}

template <typename T>
const char *Array<T>::OutOfLimitsException::what() const throw()
{
    return "out of range\n";
}

#endif // ARRAY_HPP