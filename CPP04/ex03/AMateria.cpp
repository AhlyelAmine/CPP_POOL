#include "AMateria.hpp"

AMateria::AMateria() {}

AMateria::~AMateria() {}

AMateria::AMateria(const AMateria& aMateria)
{
    *this = aMateria;
}

AMateria& AMateria::operator=(const AMateria& aMateria)
{
    if (this == &aMateria)
        return (*this);
    this->type = aMateria.type;
    return (*this);
}

AMateria::AMateria(std::string const & type) : type(type) {}

std::string const & AMateria::getType() const
{
    return (this->type);
}

void AMateria::use(ICharacter& target)
{
    std::cout << "Default use function for "<< target.getName() << "\n";
}
