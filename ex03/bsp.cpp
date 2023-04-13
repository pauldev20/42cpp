/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 03:08:37 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 00:03:33 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static Fixed	abs(Fixed const &val)
{
	if (val < 0)
		return (val * -1);
	return val;
}

static Fixed	calcArea(Point const a, Point const b, Point const c)
{
	Fixed const a1 = ((c.getY() + a.getY()) / 2) * (c.getX() - a.getX());
	Fixed const a2 = ((b.getY() + c.getY()) / 2) * (b.getX() - c.getX());
	Fixed const a3 = ((b.getY() + a.getY()) / 2) * (b.getX() - a.getX());

	return (a1 + a2 - a3);
}

bool	bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed const	abc = abs(calcArea(a, b, c));
	Fixed const	abp = abs(calcArea(a, b, point));
	Fixed const	bcp = abs(calcArea(b, c, point));
	Fixed const	cap = abs(calcArea(c, a, point));

	return (abc == abp + bcp + cap);
}
