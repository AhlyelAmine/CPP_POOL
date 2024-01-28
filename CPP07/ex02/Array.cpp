#include "Array.hpp"

template<typename T>

Array<T>::Array() : array(new T()), n(0)
{
}

template<typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), n(n)
{
    for (unsigned int i(0); i < array.size(); i++)
        this->array[i] = i;
}

template<typename T>
Array<T>::Array(Array const & array) : array(new T[array.size()]), n(array.size())
{
    for (unsigned int i(0); i < array.size(); i++)
        this->array[i] = array.array[i];
}

template<typename T>
unsigned int Array<T>::size() const
{
    return (this->n);
}

template<typename T>
Array<T>& Array<T>::operator=(Array const & array)
{
    if (this->array)
        delete [] this->array;
    this->array = new T[array.size()];
    for (unsigned int i(0); i < array.size(); i++)
    {
        this->array[i] = array.array[i];
    }
}

template<typename T>
int & Array<T>::operator[](unsigned int i)
{
    try
    {
        if (i )
        // *this->array[i];
        // return (this->array[i]);
    }
    catch (std::exception& e)
    {
        std::cout << e.what();
    }
}

template<typename T>
Array<T>::~Array()
{
    delete [] this->array;
}

template<typename T>
const char *Array<T>::OutOfLimitsException::what() const throw()
{
    return ("out of range\n");
}
