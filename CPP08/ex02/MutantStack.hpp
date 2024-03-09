#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>

template <class TYPE, class container = std::deque <TYPE> >
class MutantStack : public std::stack<TYPE, container>
{
    TYPE *array;
    size_t lenght;
    size_t capacity;
    public:
    MutantStack(){}
    MutantStack& operator=(const MutantStack& a)
    {
        (void)a;
        std::stack< TYPE, container >::operator=( a );
        return *this;
    }
    MutantStack(const MutantStack& a){a = *this;}
    MutantStack(size_t){}
    ~MutantStack(){}
    // void push(TYPE const &);
    // void pop();
    // size_t size();
    typedef typename container::iterator    iterator;

    iterator    begin() { return this->c.begin(); }
    iterator    end() { return this->c.end(); }
    // TYPE& top();
    // bool empty();
};

#include "MutantStack.tpp"

#endif
