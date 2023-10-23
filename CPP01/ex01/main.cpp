/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:59:14 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 03:59:15 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
	Zombie *pop;
	int N = 14;
	if (N < 0)
		return (0);
	pop = zombieHorde(15, "saba");
	for (int i = 0; i < 15; i ++) {
		pop[i].announce();
	}
	delete [] pop;
	return (0);
}
