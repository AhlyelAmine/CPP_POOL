#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    std::cout << "Dog Default constructor called\n";
}

Dog::Dog(const Dog& dog): Animal("Dog")
{
    std::cout << "Dog copy constructor called\n";
    *this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog assignation operator called\n";
    if (this == &dog)
        return (*this);
    this->type = dog.type;
    return (*this);
}

Dog::~Dog()
{
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "bark\n";
}
