#ifndef RPN_HPP
#define RPN_HPP

# include <iostream>
# include <stack>

class RPN
{

    std::stack<int> stack;
    public :
        RPN(){};
        RPN(const RPN&a){*this = a;};
        const RPN& operator=(const RPN&a){if (this != &a)return *this;return *this;};
        ~RPN(){};
        void rpnCalcul(std::string);
        bool rpnOperation(char);
};

#endif
