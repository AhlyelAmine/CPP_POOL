#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++) {
        if (this->slot[i])
            delete this->slot[i];
    }
}


void MateriaSource::learnMateria(AMateria* materia)
{
    if (materia) {
        for (int i = 0; i < 4; i++) {
            if (!this->slot[i])  {
                this->slot[i] = materia->clone();
                break ;
            }
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i = 3; i >= 0; i--) {
        if (this->slot[i]) {
            if (this->slot[i]->getType() == type) {
                AMateria *tmp = this->slot[i]->clone();
                // delete this->slot[i];
                // this->slot[i] = NULL;
                return (tmp);
            }
        }
    }
    return (NULL);
}
