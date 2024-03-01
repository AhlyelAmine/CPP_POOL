#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>

template <class TYPE>
class MutantStack
{
    TYPE *array;
    size_t lenght;
    size_t capacity;
    // #define iterator TYPE *;
    // #define const_iterator const TYPE *;
    public:
    MutantStack();
    MutantStack& operator=(const MutantStack& );
    MutantStack(const MutantStack& );
    MutantStack(size_t);
    ~MutantStack();
    void push(TYPE const &);
    void pop();
    size_t size();
    TYPE& top();
    bool empty();
};

#include "MutantStack.tpp"

#endif
