#include "Cat.hpp"

Cat::Cat() : Animal("Cat")
{
    std::cout << "Cat Default constructor called\n";
}

Cat::Cat(const Cat& cat) : Animal(cat.type)
{
    std::cout << "Cat copy constructor called\n";
    *this = cat;
}

Cat& Cat::operator=(const Cat& cat)
{
    std::cout << "Cat assignation operator called\n";
    this->type = cat.type;
    return (*this);
}

Cat::~Cat()
{
    std::cout << "Cat destructor called\n";
}

void Cat::makeSound() const
{
    std::cout << "meow\n";
}
