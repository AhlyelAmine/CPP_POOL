#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default Constructor called\n";
}

WrongAnimal::WrongAnimal(const std::string type) : type(type)
{
    std::cout << "WrongAnimal Constructor called\n";
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destructor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal copy Constructor called\n";
    *this = wrongAnimal;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal assignation operator called\n";
    return (*this);
}

void WrongAnimal::makeSound() const
{
    std::cout << "WrongAnimal sound\n";
}

std::string WrongAnimal::getType() const
{
    return (this->type);
}
