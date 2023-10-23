/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:59:28 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 03:59:29 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Zombie {
    private : 
        std::string name;
    public :
        Zombie();
        void setName(std::string name);
        ~Zombie();
        void announce(void);
};

Zombie* zombieHorde(int N, std::string name);
