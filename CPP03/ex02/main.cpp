#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main()
{
	ScavTrap a("saba");
	a.guardGate();
	FragTrap b("saabaa");
	b.attack("saba");
	a.attack("saabaa");
	b.highFivesGuys();
	return (0);
}