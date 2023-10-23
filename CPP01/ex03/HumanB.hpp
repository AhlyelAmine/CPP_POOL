/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:00:19 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:00:20 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanB
{
    private :
        Weapon      *weapon;
        std::string name;
    public :
        HumanB(std::string name);
        void setWeapon(Weapon &weapon);
        ~HumanB();
        void attack();
};
