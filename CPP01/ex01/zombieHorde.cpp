#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *ptr;

    if (N < 0)
        return (NULL);
    ptr = new Zombie("name");
    return (ptr);
}
