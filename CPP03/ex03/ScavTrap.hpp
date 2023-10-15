#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public virtual ClapTrap
{
    protected:
    public:
        ScavTrap(){};
        ScavTrap(std::string _name);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
};    
