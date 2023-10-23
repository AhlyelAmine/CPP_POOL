/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:59:26 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 03:59:27 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(){
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
