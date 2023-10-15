#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
    std::cout << "WrongCat constructor called\n";
}
WrongCat::~WrongCat()
{
    std::cout << "WrongCat destructor called\n";
}

void WrongCat::makeSound() const
{
    std::cout << "meow\n";
}

