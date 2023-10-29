#pragma once
#include "IMateriaSource.hpp"
#include <iostream>

class MateriaSource : public IMateriaSource
{
    private:
        AMateria *slot[4];
    public:
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const & type);
        MateriaSource();
        ~MateriaSource();
};

