#pragma once
#include <iostream>
#include "ICharacter.hpp"

class AMateria
{
    protected:
        std::string _type;
    public:
        AMateria();
        AMateria(const AMateria& materia);
        AMateria& operator=(const AMateria& materia);
        AMateria(std::string const & type);
        virtual ~AMateria();
        std::string const & getType() const;
        virtual AMateria* clone() const = 0;
        virtual void use(ICharacter& target);
};
