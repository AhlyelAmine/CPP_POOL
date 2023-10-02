#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private :
        Weapon      *weapon;
        std::string name;
    public :
        HumanB();
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        ~HumanB();
        void attack();
};