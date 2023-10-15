#pragma once
#include <iostream>

class ClapTrap
{
    protected:
        std::string _name;
        unsigned int _hitPoints;
        unsigned int _energyPoints;
        unsigned int _attackDamage;
        ClapTrap();
    public:
        ClapTrap(std::string _name);
        ClapTrap(const ClapTrap& clapTrap);
        ClapTrap& operator=(const ClapTrap& clapTrap);
        ~ClapTrap();
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
};