#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{
    private :
        DiamondTrap();
        std::string name;
    public :
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& diamondTrap);
        DiamondTrap& operator=(const DiamondTrap&diamondTrap);
        using   ScavTrap::attack;
        void whoAmI();
        ~DiamondTrap();
};
