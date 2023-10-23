/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 04:00:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 04:01:00 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main()
{
    Harl harl;
    std::string input;

    while (0x5ABA) {
        std::cout << "Enter an input : ";
        getline(std::cin, input);
        if (std::cin.eof() || input == "EXIT")
            return (0);
        harl.complain(input);
    }
    return (0);
}
