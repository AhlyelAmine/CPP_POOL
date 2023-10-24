/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:35:59 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 09:36:00 by aahlyel          ###   ########.fr       */
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
		static Fixed& min(Fixed &fixed1, Fixed &fixed2) ;
		static const Fixed& min(const Fixed &fixed1, const Fixed &fixed2) ;
		static Fixed& max(Fixed &fixed1, Fixed &fixed2) ;
		static const Fixed& max(const Fixed &fixed1, const Fixed &fixed2) ;
		Fixed operator+(const Fixed &fixed) const;
		Fixed operator-(const Fixed &fixed) const;
		Fixed operator*(const Fixed &fixed) const;
		Fixed operator/(const Fixed &fixed) const;
		bool operator<(const Fixed &fixed) const;
		bool operator<=(const Fixed &fixed) const;
		bool operator>(const Fixed &fixed) const;
		bool operator>=(const Fixed &fixed) const;
		bool operator!=(const Fixed &fixed) const;
		bool operator==(const Fixed &fixed) const;
		Fixed& operator++(void);
		Fixed operator++(int);
		Fixed& operator--(void);
		Fixed operator--(int);
};

std::ostream &operator<<(std::ostream &o, const Fixed &fixed);
