/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:00:24 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:00:25 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include "HumanB.hpp"
#include "Weapon.hpp"

int main()
{
    {
        Weapon club = Weapon("🔪");
        HumanA bob("saba", club);
        bob.attack();
        club.setType("🗡");
        bob.attack();
    }
    {
        Weapon club = Weapon("🔪");

        HumanB jim("lucifer");
        jim.setWeapon(club);
        jim.attack();
        club.setType("📎");
        jim.attack();
    }

    return 0;
}