#pragma once
#include "AMateria.hpp"

class Ice : public AMateria
{
    private:
    public:
        Ice();
        Ice(const Ice& ice);
        Ice& operator=(const Ice& ice);
        ~Ice();
        AMateria* clone() const;
        void use(ICharacter& target);
};
