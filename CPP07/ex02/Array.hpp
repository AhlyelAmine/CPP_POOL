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

        Array(): array(new T()), n(0){}

        Array(unsigned int n): array(new T[n]), n(n)
        {
            for (unsigned int i(0); i < n; i++)
                this->array[i] = rand();
        }

        Array(const Array &copy) : array(new T[copy.n]), n(copy.n)
        {
            for (unsigned int i(0); i < copy.n; i++)
                this->array[i] = copy.array[i];
        }

        Array &operator=(const Array &copy)
        {
            delete[] this->array;
            this->array = new T[copy.n];
            for (unsigned int i(0); i < copy.n; i++)
            {
                this->array[i] = copy.array[i];
            }
        }

        int &operator[](unsigned int i)
        {
            if (i >= this->n)
                throw Array::OutOfLimitsException();
            return (this->array[i]);
        }

        int &operator[](unsigned int i) const
        {
            if (i >= this->n)
                throw Array::OutOfLimitsException();
            return (this->array[i]);
        }

        unsigned int size() const
        {
            return this->n;
        }

        ~Array()
        {
            delete[] this->array;
        }
        class OutOfLimitsException : public std::exception
        {
            public:
                const char *what() const throw() {return "out of range";}
        };
};

#endif
