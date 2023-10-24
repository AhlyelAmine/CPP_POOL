/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:36:21 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 09:36:22 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>

class Fixed
{
	private:
		int					value;
		static const int	bits = 8;
	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int value);
		Fixed(const float value); 
		Fixed &operator=(const Fixed &fixed);
		~Fixed();
		int getRawBits(void) const;
		void setRawBits(int const raw);
		float toFloat(void) const;
		int toInt(void) const;
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);
