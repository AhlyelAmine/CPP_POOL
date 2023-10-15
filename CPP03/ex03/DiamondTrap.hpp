#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{
    private :
        DiamondTrap();
        std::string _name;
    public :
        DiamondTrap(std::string _name);
        DiamondTrap(const DiamondTrap& diamondTrap);
        DiamondTrap& operator=(const DiamondTrap&diamondTrap);
        using   ScavTrap::attack;
        void whoAmI();
        ~DiamondTrap();
};
