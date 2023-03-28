/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 03:08:37 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/28 03:09:09 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed const	ab = (b.getY() - a.getY()) * (point.getX() - a.getX()) - (b.getX() - a.getX()) * (point.getY() - a.getY());
	Fixed const	bc = (c.getY() - b.getY()) * (point.getX() - b.getX()) - (c.getX() - b.getX()) * (point.getY() - b.getY());
	Fixed const	ca = (a.getY() - c.getY()) * (point.getX() - c.getX()) - (a.getX() - c.getX()) * (point.getY() - c.getY());

	if ((ab >= 0 && bc >= 0 && ca >= 0) || (ab <= 0 && bc <= 0 && ca <= 0))
		return true;
	return false;
}