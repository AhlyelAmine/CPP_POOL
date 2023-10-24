#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), name(name)
{
    ClapTrap::name += "_clapname";
    FragTrap::hitPoints = 100;
    FragTrap::attackDamage = 30;
    ScavTrap::energyPoints = 50;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Diamond trap " << name << " father of clapTrap " << this->ClapTrap::name << std::endl;
}
