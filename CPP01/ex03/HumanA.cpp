/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:59:58 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 03:59:59 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"


HumanA::HumanA(std::string name, Weapon &weapon):weapon(weapon),name(name){}

HumanA::~HumanA(){}

void HumanA::attack() const
{
    std::cout << name << " attacks with their " << this->weapon.getType() << std::endl;
}
