#include "Zombie.hpp"

void Zombie::randomChump(std::string name)
{
    this->name = name;
    announce();
}