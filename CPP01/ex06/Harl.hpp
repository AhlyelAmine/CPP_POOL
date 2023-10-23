/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:01:10 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:01:11 by aahlyel          ###   ########.fr       */
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
        void complainBook(std::string level);
};

typedef void (Harl::*fnc_ptr) ( void );
