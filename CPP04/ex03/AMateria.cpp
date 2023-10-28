#pragma once
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string type;
    public:
    AMateria();
    AMateria(std::string const & type);
    AMateria& operator=(const AMateria& materia);
    virtual ~AMateria(){};
    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);
};