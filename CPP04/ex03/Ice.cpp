#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {}

Ice::Ice(const Ice& ice) : AMateria("ice")
{
    *this = ice;
}

Ice& Ice::operator=(const Ice& ice)
{
    if (this == &ice)
        return (*this);
    this->type = ice.type;
    return (*this);
}

AMateria* Ice::clone() const
{
    AMateria *materia = new Ice();
    return (materia);
}

void Ice::use(ICharacter& target)
{
    std::cout << "* shoots an ice bolt at " << target.getName() << " *\n";
}

Ice::~Ice() {}
