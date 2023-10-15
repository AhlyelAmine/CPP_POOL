#include "Animal.hpp"

Animal::Animal()
{
    std::cout << "Animal default Constractor called\n";
}

Animal::Animal(const std::string type) : type(type)
{
    std::cout << "Animal Constractor called\n";
}
Animal::~Animal()
{
    std::cout << "Animal destractor called\n";
}

Animal::Animal(const Animal& animal)
{
    std::cout << "Animal copy Constractor called\n";
    *this = animal;
}
Animal& Animal::operator=(const Animal& animal)
{
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
