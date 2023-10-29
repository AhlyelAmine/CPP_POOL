#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {}

Cure::Cure(const Cure& cure) : AMateria("cure")
{
    *this = cure;
}

Cure& Cure::operator=(const Cure& cure)
{
    if (this == &cure)
        return (*this);
    // this->type = cure.type; While assigning a Materia to another, copying the type doesn’t make sense ?
    return (*this);
}

AMateria* Cure::clone() const
{
    AMateria *materia = new Cure();
    return (materia);
}

void Cure::use(ICharacter& target)
{
    std::cout << "* heals " << target.getName() << "'s wounds *\n";
}

Cure::~Cure() {}
