#include "MutantStack.hpp"
#include <stack>
#include <iterator>
int main()
{
    // std::stack<int> mstack;
    // std::vector<int> lol;
    // std::vector<int>::iterator a = lol.begin();
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.top() << std::endl;
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    std::cout << mstack.top() << std::endl;
    std::cout << mstack.size() << std::endl;
    mstack.push(0);
    // MutantStack<int>::iterator it = mstack.begin();
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite)
    // {
    // std::cout << *it << std::endl;
    // ++it;
    // }
    // std::stack<int> s(mstack);
    return 0;
}