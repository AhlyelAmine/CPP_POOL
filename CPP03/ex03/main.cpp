#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	DiamondTrap a("saba");
	a.whoAmI();
	a.attack("alien");
	a.guardGate();
	a.highFivesGuys();
	a.takeDamage(100);
	a.beRepaired(100);
	std::cout << a.getName() << std::endl;
	return (0);
}
