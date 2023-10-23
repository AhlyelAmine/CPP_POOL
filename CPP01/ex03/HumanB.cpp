/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:00:14 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:00:15 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

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
