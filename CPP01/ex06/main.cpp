/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:01:13 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:01:14 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    std::string input;

    if (ac == 2) {
        input = av[1];
        harl.complainBook(input);
    }
    else
        std::cout << "Usage : ./harFile <log level>" << std::endl;
    return (0);
}
