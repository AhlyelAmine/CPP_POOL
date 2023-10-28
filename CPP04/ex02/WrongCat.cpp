#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called\n";
}

WrongCat::WrongCat(const WrongCat& wrongCat) : WrongAnimal(wrongCat)
{
    std::cout << "WrongCat copy constructor called\n";
    *this = wrongCat;
}

WrongCat& WrongCat::operator=(const WrongCat& wrongCat)
{
    std::cout << "WrongCat assignation operator called\n";
    this->type = wrongCat.type;
    return (*this);
}

WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << "meow\n";
}

