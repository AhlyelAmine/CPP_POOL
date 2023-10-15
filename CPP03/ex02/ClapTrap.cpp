#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string _name) : _name(_name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap Constructor called for " << _name  << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap copy constructor called" << std::endl;
	*this = clapTrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
	std::cout << "ClapTrap assignement operator called" << std::endl;
	this->_name = clapTrap._name;
	this->_hitPoints = clapTrap._hitPoints;
	this->_energyPoints = clapTrap._energyPoints;
	this->_attackDamage = clapTrap._attackDamage;
	return (*this);
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints >= amount) 
		_hitPoints -= amount;
	else
		_hitPoints -= _hitPoints;
	std::cout << "ClapTrap damaged " << amount << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (_energyPoints > 0) {
		_energyPoints -= 1;
		_hitPoints += amount;
	}
	else
		std::cout << "no energy points left" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
	if (_energyPoints > 0 && _hitPoints > 0) {
		_energyPoints -= 1;
		std::cout << "ClapTrap " << _name << " attacks "<< target << ", causing "<< _attackDamage <<" points of damage!" << std::endl;
	}
	else if (_hitPoints <= 0)
		std::cout << "ScavTrap no hitPoints" << std::endl;
	else if (_energyPoints <= 0)
		std::cout << "ScavTrap no energy points left" << std::endl;
}
