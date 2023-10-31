#pragma once
#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter
{
    private:
        std::string name;
        AMateria    *slot[4];
        AMateria    *garbage;
    public:
        Character();
        Character(const std::string name);
        Character(const Character& character);
        Character& operator=(const Character& character);
        std::string const & getName() const;
        void equip(AMateria* m);
        void unequip(int idx);
        void use(int idx, ICharacter& target);
        void clean(void);
        ~Character();
};
