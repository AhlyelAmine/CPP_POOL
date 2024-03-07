#include "MutantStack.hpp"

// template <class TYPE>
// MutantStack<TYPE>::MutantStack() : array(NULL), lenght(0), capacity(0) {}
// template <class TYPE>
// MutantStack<TYPE>::MutantStack(size_t n) : array(new TYPE[n]), lenght(n), capacity(n) {}
// template <class TYPE>
// MutantStack<TYPE>::~MutantStack() { delete[] array; }
// template <class TYPE>
// MutantStack<TYPE>::MutantStack(const MutantStack& stack)
// {
//     *this = stack;
// }
// template <class TYPE, class container>
// MutantStack<TYPE, container>& MutantStack<TYPE>::operator=(const MutantStack& stack)
// {
    // if (this != &stack)
        // return (*this);
    // return (*this);
    // if (this->array)
    // {
        // delete this->array;
        // this->array = NULL;
    // }
    // if (stack.array)
    // {
        // this->array = new TYPE[stack.lenght];
        // for (size_t i = 0; i < this->lenght; i++)
        // {
            // this->array[i] = stack.array[i];
        // }
    // }
    // this->lenght = stack.lenght;
    // this->capacity = stack.lenght;
// }
// template <class TYPE>
// void MutantStack<TYPE>::push(TYPE const &t)
// {
//     if (this->lenght == this->capacity)
//     {
//         this->capacity = this->capacity * 2 + 1;
//         TYPE *newArray = new TYPE[this->capacity];
//         for (size_t i = 0; i < this->lenght; i++)
//         {
//             newArray[i] = array[i];
//         }
//         delete this->array;
//         this->array = newArray;
//     }
//     this->array[this->lenght] = t;
//     this->lenght++;
// }

// template <class TYPE>
// void MutantStack<TYPE>::pop()
// {
//     if (this->lenght == 0)
//         throw "stack empty\n";
//     this->lenght--;
// }
// template <class TYPE>
// size_t MutantStack<TYPE>::size()
// {
//     return (this->lenght);
// }
// template <class TYPE>
// bool MutantStack<TYPE>::empty()
// {
//     return (this->lenght == 0);
// }
// template <class TYPE>
// TYPE& MutantStack<TYPE>::top()
// {
//     if (this->lenght == 0)
//         throw "stack empty\n";
//     return (this->array[lenght - 1]);
// }

