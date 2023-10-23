/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:58:45 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 03:58:46 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *lucifer;

	randomChump("saba");
	lucifer = newZombie("👺");
	lucifer->announce();
	delete(lucifer);
	return (0);
}
