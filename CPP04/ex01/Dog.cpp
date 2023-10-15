#include "Dog.hpp"

Dog::Dog() : Animal("Dog")
{
    brain = new Brain();
    std::cout << "Dog constructor called\n";
}
Dog::~Dog()
{
    delete brain;
    std::cout << "Dog destructor called\n";
}

void Dog::makeSound() const
{
    std::cout << "bark\n";
}
