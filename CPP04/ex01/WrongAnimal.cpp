#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    std::cout << "WrongAnimal default Constractor called\n";
}

WrongAnimal::WrongAnimal(const std::string type) : type(type)
{
    std::cout << "WrongAnimal Constractor called\n";
}
WrongAnimal::~WrongAnimal()
{
    std::cout << "WrongAnimal destractor called\n";
}

WrongAnimal::WrongAnimal(const WrongAnimal& wrongAnimal)
{
    std::cout << "WrongAnimal copy Constractor called\n";
    *this = wrongAnimal;
}
WrongAnimal& WrongAnimal::operator=(const WrongAnimal& wrongAnimal)
{
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
