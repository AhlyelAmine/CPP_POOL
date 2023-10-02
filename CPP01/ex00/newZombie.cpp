#include "Zombie.hpp"

Zombie* Zombie::newZombie(std::string name)
{
    Zombie *zombie;

    zombie = new Zombie;
    zombie->name = name;
    return (zombie);
}