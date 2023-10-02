#include "HumanB.hpp"

HumanB::HumanB(){
    this->weapon = NULL;
}

HumanB::HumanB(std::string name):name(name){
    this->weapon = NULL;
}

HumanB::~HumanB(){}

void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
}

void HumanB::attack()
{
    if (weapon != NULL) {
        std::cout << name << " attacks with their " << weapon->getType() << std::endl;
    }
    else
        std::cout << name << " no weapon 😱" << std::endl;
}