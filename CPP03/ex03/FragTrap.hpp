#pragma once
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    protected:
    public:
        FragTrap(){};
        FragTrap(std::string _name);
        ~FragTrap();
        void highFivesGuys();
};