#pragma once
#include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
    public:
        ClapTrap(){std::cout << "wtf i am doing here\n";};
        ClapTrap(std::string _name);
        ClapTrap(const ClapTrap& clapTrap);
        ClapTrap& operator=(const ClapTrap& clapTrap);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};