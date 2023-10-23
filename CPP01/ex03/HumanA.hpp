/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:00:09 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:00:10 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Weapon.hpp"

class HumanA
{
	private :
		Weapon		&weapon;
		std::string	name;
	public :
		HumanA(std::string name, Weapon &weapon);
		~HumanA();
		void attack() const;
};
