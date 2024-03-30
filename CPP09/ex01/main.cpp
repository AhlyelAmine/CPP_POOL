#include "RPN.hpp"
#include <sstream>

int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        RPN rpn;
        std::stringstream a(argv[1]);
        do
        {
            std::string token;
            a >> token;
            if (token.size() != 1)
            {
                std::cerr << "Error\n";        
                return 0;
            }
            if (isdigit(token[0]))
                rpn.stack.push(token[0] - 48);
            else
            {
                if (rpn.stack.size() < 2)
                {
                    std::cerr << "Error\n";        
                    return 0;
                }
                int tmp = rpn.stack.top();
                rpn.stack.pop();
                switch (token[0])
                {
                    case '-':
                        tmp = rpn.stack.top() - tmp;
                        break;
                    case '+':
                        tmp = rpn.stack.top() + tmp;
                        break;
                    case '/':
                        if (!tmp)
                        {
                            std::cerr << "Error\n";        
                            return 0;
                        }
                        tmp = rpn.stack.top() / tmp;
                        break;
                    case '*':
                        tmp = rpn.stack.top() * tmp;
                        break;
                    default :
                        std::cerr << "Error\n";        
                        return 0;
                }
                rpn.stack.pop();
                rpn.stack.push(tmp);
            }
        } while (!a.eof());
        if (rpn.stack.size() == 1)
            std::cout << rpn.stack.top();
        else
            std::cerr << "Error\n";        
    }
    else
        std::cerr << "Error\n";
    return 0;
}
