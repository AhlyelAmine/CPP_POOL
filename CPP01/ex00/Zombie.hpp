/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:59:05 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 03:59:06 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie {
    private : 
        std::string name;
    public :
        Zombie();
        Zombie(std::string name);
        ~Zombie();
        void announce(void);
};

Zombie* newZombie(std::string name);
void randomChump(std::string name);
