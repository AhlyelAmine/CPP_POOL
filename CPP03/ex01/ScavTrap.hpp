#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        ScavTrap();
    public:
        ScavTrap(std::string _name);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
};