#pragma once
#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
    private:
        ScavTrap();
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        void guardGate();
        void attack(const std::string& target);
};