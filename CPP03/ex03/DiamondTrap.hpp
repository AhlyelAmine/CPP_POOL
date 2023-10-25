#pragma once
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap , public ScavTrap
{
    private :
        std::string name;
    public :
        DiamondTrap();
        DiamondTrap(std::string name);
        DiamondTrap(const DiamondTrap& diamondTrap);
        DiamondTrap& operator=(const DiamondTrap&diamondTrap);
        using   ScavTrap::attack;
        void    whoAmI();
        const std::string& getName() const;
        ~DiamondTrap();
};
