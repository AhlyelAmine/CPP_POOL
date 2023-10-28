#pragma once
#include "AMateria.hpp"

class Cure : public AMateria
{
private:
    /* data */
public:
    Cure(/* args */);
    AMateria* clone() const {return new Cure(*this);};
    ~Cure();
};

Cure::Cure() : AMateria("cure")
{
    std::cout << "Cure constructor called" << std::endl;
}

Cure::~Cure()
{
    std::cout << "Cure destructor called" << std::endl;
}
