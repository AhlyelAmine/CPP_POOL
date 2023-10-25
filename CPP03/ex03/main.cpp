#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include "FragTrap.hpp"
#include "ClapTrap.hpp"

int main()
{
	DiamondTrap a("saba");
	a.whoAmI();
	a.attack("alo");
	std::cout << a.getName() << std::endl;
	return (0);
}
