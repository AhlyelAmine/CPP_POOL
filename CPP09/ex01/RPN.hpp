#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{

    public :
    std::stack<int> stack;
        RPN(){};
        RPN(const RPN&a){*this = a;};
        const RPN& operator=(const RPN&a){if (this != &a)return *this;return *this;};
        ~RPN(){};
};

#endif
