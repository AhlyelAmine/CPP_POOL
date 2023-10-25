#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap a("saba");
	a.guardGate();
	a.attack("alien");
	FragTrap b("saba");
	b.attack("alien");
	b.highFivesGuys();
	b.takeDamage(10);
	b.beRepaired(100);
	return (0);
}
