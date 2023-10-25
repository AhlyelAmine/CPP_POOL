#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap("name")
{
    std::cout << "FragTrap Default constructor called"  << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
    std::cout << "FragTrap Constructor called"  << std::endl;
    this->hitPoints = 100;
    this->energyPoints = 100;
    this->attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& fragTrap)
{
    std::cout << "FragTrap Copy constructor called"  << std::endl;
    *this = fragTrap;
}

FragTrap& FragTrap::operator=(const FragTrap& fragTrap)
{
    std::cout << "FragTrap Assignation operator called"  << std::endl;
    this->name = fragTrap.name;
    this->hitPoints = fragTrap.hitPoints;
    this->energyPoints = fragTrap.energyPoints;
    this->attackDamage = fragTrap.attackDamage;
    return (*this);
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap destructor called" << std::endl;
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap high five"  << std::endl;
}
