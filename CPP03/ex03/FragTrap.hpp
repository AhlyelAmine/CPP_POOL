#pragma once
#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    public:
        FragTrap();
        FragTrap(const FragTrap& fragTrap);
        FragTrap& operator=(const FragTrap& fragTrap);
        FragTrap(std::string name);
        ~FragTrap();
        void highFivesGuys();
};
