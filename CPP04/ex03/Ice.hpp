#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
        /* data */
    public:
        Ice();
        AMateria* clone() const {return new Ice(*this);};
        ~Ice();
};

Ice::Ice() : AMateria("ice")
{
    std::cout << "Ice constructor called" << std::endl;
}

Ice::~Ice()
{
    std::cout << "Ice destructor called" << std::endl;
}
