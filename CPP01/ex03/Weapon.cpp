/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:00:31 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:00:32 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(){};
Weapon::~Weapon(){}
Weapon::Weapon(std::string type):type(type){}

const std::string& Weapon::getType() const
{
    return (this->type);
}
void Weapon::setType(std::string type)
{
    this->type = type;
}
