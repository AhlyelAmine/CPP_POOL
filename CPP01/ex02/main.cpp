/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 03:59:38 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 03:59:39 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main()
{
    std::string var = "HI THIS IS BRAIN";

    std::string *stringPTR = &var;
    std::string &stringREF = var;
    std::cout << &var << std::endl;
    std::cout << stringPTR << std::endl;
    std::cout << &stringREF << std::endl;
    std::cout << var << std::endl;
    std::cout << *stringPTR << std::endl;
    std::cout << stringREF << std::endl;
}
