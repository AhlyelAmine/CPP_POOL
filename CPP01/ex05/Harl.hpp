/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:00:56 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:00:57 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

class Harl
{
    private :
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public :
        Harl();
        ~Harl();
        void complain(std::string level);
};

typedef void (Harl::*fnc_ptr) ( void );
