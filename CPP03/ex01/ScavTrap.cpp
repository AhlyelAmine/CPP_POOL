#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap("name")
{
	std::cout << "ScavTrap Default Constructor called"  << std::endl;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
    std::cout << "ScavTrap Constructor called"  << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap& scavTrap)
{
	std::cout << "ScavTrap Copy constructor called"  << std::endl;
	*this = scavTrap;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& scavTrap)
{
	std::cout << "ScavTrap Assignation operator called"  << std::endl;
	this->name = scavTrap.name;
	this->hitPoints = scavTrap.hitPoints;
	this->energyPoints = scavTrap.energyPoints;
	this->attackDamage = scavTrap.attackDamage;
	return (*this);
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