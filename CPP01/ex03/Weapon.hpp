/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:00:36 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:00:37 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Weapon
{
    private :
        std::string type;
    public :
        Weapon();
        Weapon(std::string type);
        ~Weapon();
        const std::string& getType() const;
        void setType(std::string type);
};
