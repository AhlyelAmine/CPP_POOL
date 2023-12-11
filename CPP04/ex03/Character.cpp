#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "AMateria.hpp"

Character::Character() : name("name")
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
    this->garbage = NULL;
}

Character::Character(const std::string name) : name(name)
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
    this->garbage = NULL;
}

Character::Character(const Character& character)
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
    this->garbage = NULL;
    *this = character;
}

Character& Character::operator=(const Character& character)
{
    if (this == &character)
        return (*this);
    for (int i = 0; i < 4; i++) {
        if (this->slot[i])
            delete this->slot[i];
        if (character.slot[i]) {
            if (character.slot[i]->getType() == "ice")
                this->slot[i] = new Ice(*(Ice *)character.slot[i]);
            else
                this->slot[i] = new Cure(*(Cure *)character.slot[i]);
        }
        else
            this->slot[i] = NULL;
    }
    if (this->garbage)
        delete this->garbage;
    this->garbage = NULL;
    this->name = character.name;
    return (*this);
}

std::string const & Character::getName() const
{
    return (this->name);
}

void Character::equip(AMateria* m)
{
    for (int i = 0; i < 3; i++) {
        if (!this->slot[i]) {
            this->slot[i] = m;
            break;
        }
    }
}

void Character::unequip(int idx)
{
    if (idx > 3 || idx < 0 || !this->slot[idx])
        return ;
    clean();
    this->garbage = this->slot[idx];
    this->slot[idx] = NULL;
}

void Character::clean(void)
{
    if (this->garbage)
    {
        delete this->garbage;
        this->garbage = NULL;
    }
}

void Character::use(int idx, ICharacter& target)
{
    if (idx > 3 || idx < 0 || !this->slot[idx])
        return ;
    this->slot[idx]->use(target);
}

Character::~Character() 
{
    for (int i = 0; i < 4; i++) {
        if (this->slot[i])
            delete this->slot[i];
    }
    if (this->garbage)
    {
        delete this->garbage;
        this->garbage = NULL;
    }
}
