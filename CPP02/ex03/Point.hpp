/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:37:23 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 09:37:24 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Fixed.hpp"

class Point {
    private :
        const Fixed x;
        const Fixed y;
    public :
        Point();
        Point(const Point &point);
        Point(const float x, const float y);
        Point& operator=(const Point &point);
        ~Point();
        Fixed getX() const;
        Fixed getY() const;
};
bool bsp( Point const a, Point const b, Point const c, Point const point);