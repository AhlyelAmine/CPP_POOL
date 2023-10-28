#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called\n";
}

Brain::Brain(const Brain& brain)
{
    *this = brain;
}

Brain& Brain::operator=(const Brain& brain)
{
    *this->ideas = *brain.ideas;
    return (*this);
}

Brain::~Brain()
{
    std::cout << "Brain destructor called\n";
}
