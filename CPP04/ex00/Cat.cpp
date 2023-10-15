#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat constructor called\n";
}
Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "meow\n";
}

