#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    brain = new Brain();
    std::cout << "Cat constructor called\n";
}
Cat::~Cat()
{
    delete brain;
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "meow\n";
}

