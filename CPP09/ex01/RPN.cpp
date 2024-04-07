#include "RPN.hpp"
#include <sstream>

RPN::RPN(){}
RPN::~RPN(){}
RPN::RPN(const RPN&a)
{
    *this = a;
}
const RPN& RPN::operator=(const RPN&a)
{
    if (this == &a)
        return *this;
    this->stack = a.stack;
    return *this;
}

bool RPN::rpnOperation(char token)
{
    int tmp = this->stack.top();

    this->stack.pop();

    switch (token)
    {
        case '-':
            tmp = this->stack.top() - tmp;
            break;
        case '+':
            tmp = this->stack.top() + tmp;
            break;
        case '/':
            if (!tmp)
                return false;
            tmp = this->stack.top() / tmp;
            break;
        case '*':
            tmp = this->stack.top() * tmp;
            break;
        default :
            return false;
    }

    this->stack.pop();
    this->stack.push(tmp);
    return true;
}

void RPN::rpnCalcul(std::string input)
{
    std::stringstream a(input);
    do
    {
        std::string token;
        a >> token;
        if (a.eof() && !token.size())
            break;
        if (token.size() != 1)
        {
            std::cerr << "\'"<< token << "\'" << "3Error\n";
            return ;
        }
        if (isdigit(token[0]))
            this->stack.push(token[0] - 48);
        else
        {
            if (this->stack.size() < 2)
            {
                std::cerr << "4Error\n";
                return ;
            }
            if (!rpnOperation(token[0]))
            {
                std::cerr << "5Error\n";
                return ;
            }
        }
    } while (!a.eof());

    if (this->stack.size() == 1)
        std::cout << this->stack.top();
    else
        std::cerr << "6Error\n";
}
