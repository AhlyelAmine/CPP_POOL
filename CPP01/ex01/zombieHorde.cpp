#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
    Zombie *ptr;

    if (N < 0)
        return (NULL);
    ptr = new Zombie[N];
    for (int i = 0; i < N; i++)
        ptr[i].setName(name);
    return (ptr);
}
