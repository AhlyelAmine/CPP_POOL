#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const ScavTrap& scavTrap);
        ScavTrap& operator=(const ScavTrap& scavTrap);
        ScavTrap(std::string name);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
};
