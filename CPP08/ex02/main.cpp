#include "MutantStack.hpp"
#include <stack>
#include <iterator>

int main()
{
    MutantStack<int > stack;

    stack.push(4);
    stack.push(8);
    stack.push(4);
    stack.push(5);
    std::cout << stack.top();
    stack.pop();
    std::cout << stack.top();
    stack.pop();
    std::cout << stack.top();
    stack.pop();
    std::cout << stack.top() << std::endl;
    stack.pop();
    stack.push(42);
    stack.push(37);
    stack.push(13);
    std::cout << stack.size() << std::endl;
    std::cout << stack.top();
    stack.pop();
    std::cout << stack.top() << std::endl;

    std::cout << stack.size() << std::endl;
    stack.push(0);

    std::cout << "-------------------------------\n"; 
    MutantStack<int>::iterator it = stack.end();
    do
    {
        it--;
        std::cout << *it << std::endl;
    }
    while (it != stack.begin());
    std::cout << "-------------------------------\n"; 

    /*
        the ability to convert MutantStack to regular std::stack container
    */
    std::cout << "-------------------------------\n"; 
    std::stack<int> regularStack(stack);
    while (!regularStack.empty())
    {
        std::cout << regularStack.top() << std::endl;
        regularStack.pop();
    }
    std::cout << "-------------------------------\n"; 
    return 0;
}
