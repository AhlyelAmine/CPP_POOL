/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aahlyel <aahlyel@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 09:36:14 by aahlyel           #+#    #+#             */
/*   Updated: 2023/10/23 09:36:15 by aahlyel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"
#define myabs(x) ((x) < 0 ? -(x) : (x))

bool bsp(Point const a, Point const b, Point const c, Point const point)
{

    Fixed surfaceABC(myabs((a.getX() * (b.getY() - c.getY()) + b.getX() * (c.getY() - a.getY()) + c.getX() * (a.getY() - b.getY())).toFloat()) / 2);
    Fixed surfaceABP(myabs((a.getX() * (b.getY() - point.getY()) + b.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - b.getY())).toFloat()) / 2);
    Fixed surfaceACP(myabs((a.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - a.getY()) + point.getX() * (a.getY() - c.getY())).toFloat()) / 2);
    Fixed surfaceBCP(myabs((b.getX() * (c.getY() - point.getY()) + c.getX() * (point.getY() - b.getY()) + point.getX() * (b.getY() - c.getY())).toFloat()) / 2);
    return (surfaceABC == (surfaceABP + surfaceACP + surfaceBCP));
}
