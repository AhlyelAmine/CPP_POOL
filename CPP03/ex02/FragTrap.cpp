#include "FragTrap.hpp"

FragTrap::FragTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "FragTrap Constructor called"  << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 100;
    this->_attackDamage = 30;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap high five"  << std::endl;
}
