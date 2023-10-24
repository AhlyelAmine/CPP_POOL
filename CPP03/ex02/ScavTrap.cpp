#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Constructor called"  << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << "  is now in Gate keeper mode."  << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (energyPoints > 0 && hitPoints > 0) {
		energyPoints -= 1;
		std::cout << "ScavTrap " << name << " attacks "<< target << ", causing "<< attackDamage <<" points of damage!" << std::endl;
	}
	else if (hitPoints <= 0)
		std::cout << "ScavTrap no hitPoints" << std::endl;
	else if (energyPoints <= 0)
		std::cout << "ScavTrap no energy points left" << std::endl;
}