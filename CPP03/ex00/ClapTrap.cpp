#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hitPoints(10), energyPoints(10), attackDamage(0)
{
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& clapTrap)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = clapTrap;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& clapTrap)
{
    std::cout << "Assignement operator called" << std::endl;
    this->name = clapTrap.name;
    this->hitPoints = clapTrap.hitPoints;
    this->energyPoints = clapTrap.energyPoints;
    this->attackDamage = clapTrap.attackDamage;
    return (*this);
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints >= amount) 
        hitPoints -= amount;
    else
        hitPoints -= hitPoints;
    std::cout << "ClapTrap damaged " << amount << " hit points" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (energyPoints > 0) {
        energyPoints -= 1;
        hitPoints += amount;
    }
    else
        std::cout << "no energy points left" << std::endl;
}

void ClapTrap::attack(const std::string& target)
{
    if (energyPoints > 0 && hitPoints > 0) {
        energyPoints -= 1;
        std::cout << "ClapTrap " << name << " attacks "<< target << ", causing "<< attackDamage <<" points of damage!" << std::endl;
    }
    else if (hitPoints <= 0)
        std::cout << "no hitPoints" << std::endl;
    else if (energyPoints <= 0)
        std::cout << "no energy points left" << std::endl;
}

