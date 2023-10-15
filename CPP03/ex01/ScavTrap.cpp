#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string _name) : ClapTrap(_name)
{
    std::cout << "ScavTrap Constructor called"  << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap destructor called" << std::endl;
}

void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << _name << "  is now in Gate keeper mode."  << std::endl;
}

void ScavTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints -= 1;
		std::cout << "ScavTrap " << _name << " attacks "<< target << ", causing "<< _attackDamage <<" points of damage!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap no hitPoints" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap no energy points left" << std::endl;
}