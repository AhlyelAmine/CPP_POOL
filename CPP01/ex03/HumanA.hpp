#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private :
		Weapon		&weapon;
		std::string	name;
		HumanA();
	public :
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack() const;
};
