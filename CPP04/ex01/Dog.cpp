#include "Dog.hpp"

Dog::Dog() : Animal("Dog"), brain(new Brain())
{
    std::cout << "Dog default constructor called\n";
}

Dog::Dog(const Dog& dog) : Animal(dog)
{
    std::cout << "Dog copy constructor called\n";
    this->brain = NULL;
    *this = dog;
}

Dog& Dog::operator=(const Dog& dog)
{
    std::cout << "Dog assignation operator called\n";
    if (this == &dog)
        return (*this);
    if (this->brain)
        delete this->brain;
    this->brain = new Brain(*dog.brain);
    this->type = dog.type;
    return (*this);
}

Dog::~Dog()
{
    delete this->brain;
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "Bark\n";
}
