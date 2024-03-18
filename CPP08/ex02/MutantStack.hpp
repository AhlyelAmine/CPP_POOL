#ifndef MUTANT_STACK_HPP
#define MUTANT_STACK_HPP

#include <iostream>
#include <stack>

template <class _Type>
class MutantStack : public std::stack<_Type>
{
    public:
        MutantStack(){}
        MutantStack& operator=(const MutantStack& objet)
        {
            std::stack< _Type>::operator=(objet);
            return *this;
        }
        MutantStack(const MutantStack& a){a = *this;}
        ~MutantStack(){};

        typedef typename std::deque <_Type >::iterator    iterator;

        iterator    begin() { return this->c.begin(); }
        iterator    end() { return this->c.end(); }
};

#endif
