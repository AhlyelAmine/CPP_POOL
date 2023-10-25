#include "ClapTrap.hpp"

int main()
{
	ClapTrap a("alo");
	ClapTrap b("pop");
	ClapTrap c(a);
	a.attack("d");
	a.takeDamage(15);
	a.takeDamage(150);
	a.beRepaired(100);
	return (0);
}