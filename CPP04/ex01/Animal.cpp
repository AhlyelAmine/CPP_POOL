#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default constructor called\n";
}

Animal::Animal(const std::string type) : type(type)
{
    std::cout << "Animal constructor called\n";
}

Animal::~Animal()
{
    std::cout << "Animal destructor called\n";
}

Animal::Animal(const Animal& animal)
{
    std::cout << "Animal copy constructor called\n";
    *this = animal;
}

Animal& Animal::operator=(const Animal& animal)
{
    this->type = animal.type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Animal sound\n";
}

std::string Animal::getType() const
{
    return (this->type);
}
