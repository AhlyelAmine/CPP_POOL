#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string _name) : ClapTrap(_name), FragTrap(_name), ScavTrap(_name), _name(_name)
{
    ClapTrap::_name += "_clap_name";
    FragTrap::_hitPoints = 100;
    FragTrap::_attackDamage = 30;
    ScavTrap::_energyPoints = 50;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Diamond trap " << _name << " father of clapTrap " << this->ClapTrap::_name << std::endl;
}
