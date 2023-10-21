#include "Zombie.hpp"

int main()
{
	Zombie *pop;
	int N = 14;
	if (N < 0)
		return (0);
	pop = zombieHorde(15, "saba");
	for (int i = 0; i < 15; i ++) {
		pop[i].announce();
	}
	delete [] pop;
	return (0);
}
