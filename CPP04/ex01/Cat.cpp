#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    std::cout << "Cat default constructor called\n";
}

Cat::Cat(const Cat& cat) : Animal(cat)
{ 
    std::cout << "Cat copy constructor called\n";
    *this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat assignation operator called\n";
    if (this == &cat)
        return (*this);
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*cat.brain);
    this->type = cat.type;
    return (*this);
}

Cat::~Cat()
{
    delete this->brain;
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "Meow\n";
}
