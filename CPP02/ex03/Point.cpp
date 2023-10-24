/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:37:12 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 09:37:13 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : x(0), y(0) {}

Point::Point(const Point &point) {
    *this = point;
}

Point& Point::operator=(const Point &point) {
    (Fixed)this->x = point.getX();
    (Fixed)this->y = point.getY();
    return (*this);
}

Point::Point(const float x, const float y) : x(x), y(y) {}

Point::~Point(){}

Fixed Point::getX() const {
    return (this->x);
}

Fixed Point::getY() const {
    return (this->y);
}
