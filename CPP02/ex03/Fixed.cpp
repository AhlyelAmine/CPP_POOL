/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:36:04 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 09:36:05 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed() : value(0) {}

Fixed::Fixed(const int value) : value(value << this->bits) {}

Fixed::Fixed(const float value) : value(roundf(value * (1 << this->bits))) {}

Fixed::Fixed(const Fixed &fixed) {
	*this = fixed;
}

Fixed& Fixed::operator=(const Fixed &fixed) {
	this->value = fixed.getRawBits();
	return (*this);
}

Fixed::~Fixed() {}

int Fixed::getRawBits(void) const {
	return (this->value);
}

void Fixed::setRawBits(int const raw) {
	this->value = raw;
}

float Fixed::toFloat(void) const {
	return ((float)this->value / (float)(1 << this->bits));
}

int Fixed::toInt(void) const {
	return (this->value >> this->bits);
}

Fixed Fixed::operator+(const Fixed &fixed) const {
	return (Fixed(this->toFloat() + fixed.toFloat()));
}

Fixed Fixed::operator-(const Fixed &fixed) const {
	return (Fixed(this->toFloat() - fixed.toFloat()));
}

Fixed Fixed::operator*(const Fixed &fixed) const {
	return (Fixed(this->toFloat() * fixed.toFloat()));
}

Fixed Fixed::operator/(const Fixed &fixed) const {
	return (Fixed(this->toFloat() / fixed.toFloat()));
}

bool Fixed::operator<(const Fixed &fixed) const {
	return this->getRawBits() < fixed.getRawBits();
}
bool Fixed::operator<=(const Fixed &fixed) const {
	return this->getRawBits() <= fixed.getRawBits();
}
bool Fixed::operator>(const Fixed &fixed) const {
	return this->getRawBits() > fixed.getRawBits();
}
bool Fixed::operator>=(const Fixed &fixed) const {
	return this->getRawBits() >= fixed.getRawBits();
}
bool Fixed::operator==(const Fixed &fixed) const {
	return this->getRawBits() == fixed.getRawBits();
}
bool Fixed::operator!=(const Fixed &fixed) const {
	return this->getRawBits() != fixed.getRawBits();
}

Fixed& Fixed::operator++(void) {
	++this->value;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed tmp(*this);
	tmp.value = this->value++;
	return (tmp);
}

Fixed& Fixed::operator--(void) {
	--this->value;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed tmp(*this);
	tmp.value = this->value--;
	return (*this);
}

Fixed& Fixed::min(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}
const Fixed& Fixed::min(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 <= fixed2 ? fixed1 : fixed2);
}
Fixed& Fixed::max(Fixed &fixed1, Fixed &fixed2) {
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}
const Fixed& Fixed::max(const Fixed &fixed1, const Fixed &fixed2) {
	return (fixed1 >= fixed2 ? fixed1 : fixed2);
}

std::ostream& operator<<(std::ostream &o, const Fixed &fixed)
{
	o << fixed.toFloat();
	return (o);
}
