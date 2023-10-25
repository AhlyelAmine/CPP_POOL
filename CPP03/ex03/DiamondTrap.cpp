#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("name"), FragTrap("name"), ScavTrap("name"), name("name")
{
    ClapTrap::name += "_clapname";
    FragTrap::hitPoints = 100;
    FragTrap::attackDamage = 30;
    ScavTrap::energyPoints = 50;
    std::cout << "DiamondTrap Default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name), FragTrap(name), ScavTrap(name), name(name)
{
    ClapTrap::name += "_clapname";
    FragTrap::hitPoints = 100;
    FragTrap::attackDamage = 30;
    ScavTrap::energyPoints = 50;
    std::cout << "DiamondTrap constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& diamondTrap)
{
    std::cout << "DiamondTrap Copy constructor called" << std::endl;
    *this = diamondTrap;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& diamondTrap)
{
    std::cout << "DiamondTrap Assignation operator called" << std::endl;
    this->name = diamondTrap.name;
    this->hitPoints = diamondTrap.hitPoints;
    this->energyPoints = diamondTrap.energyPoints;
    this->attackDamage = diamondTrap.attackDamage;
    return (*this);
}

const std::string& DiamondTrap::getName() const
{
    return (this->name);
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap destructor called" << std::endl;
}

void DiamondTrap::whoAmI()
{
    std::cout << "Diamond trap " << name << " father of clapTrap " << this->ClapTrap::name << std::endl;
}
