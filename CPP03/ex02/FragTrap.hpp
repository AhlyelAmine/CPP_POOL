#pragma once
#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
    private:
        FragTrap();
    public:
        FragTrap(std::string _name);
        ~FragTrap();
        void highFivesGuys();
};