#include "Zombie.hpp"

Zombie::Zombie(){
    std::cout << "Zombie created" << std::endl;
}

Zombie::Zombie(std::string name) : name(name){
    std::cout << "Zombie created" << std::endl;
}

Zombie::~Zombie(){
    std::cout << "Zombie " << name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
void Zombie::setName(std::string name)
{
    this->name = name;
}
