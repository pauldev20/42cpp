/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 03:18:16 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 01:08:02 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point);

int	main(void)
{
	Point const a(Fixed(0), Fixed(0));
	Point const b(Fixed(7), Fixed(0));
	Point const c(Fixed(3), Fixed(5));

	// std::cout << "A: x:" << a.getX() << " y:" << a.getY() << std::endl;
	// std::cout << "B: x:" << b.getX() << " y:" << b.getY() << std::endl;
	// std::cout << "C: x:" << c.getX() << " y:" << c.getY() << std::endl << std::endl;

	Point const p1(Fixed(3), Fixed(1));
	// std::cout << "P: x:" << p1.getX() << " y:" << p1.getY() << std::endl;
	if (bsp(a, b, c, p1))
		std::cout << "P is inside the triangle" << std::endl;
	else
		std::cout << "P is outside the triangle" << std::endl;

	Point const p2(Fixed(3), Fixed(8));
	// std::cout << "P: x:" << p2.getX() << " y:" << p2.getY() << std::endl;
	if (bsp(a, b, c, p2))
		std::cout << "P is inside the triangle" << std::endl;
	else
		std::cout << "P is outside the triangle" << std::endl;

	if (bsp(Point(0, 0), Point(20, 30), Point(40, 0), Point(20, 15)))
		std::cout << "P is inside the triangle" << std::endl;
	else
		std::cout << "P is outside the triangle" << std::endl;

	if (bsp(Point(10, 0), Point(30, 30), Point(50, 0), Point(30, 15)))
		std::cout << "P is inside the triangle" << std::endl;
	else
		std::cout << "P is outside the triangle" << std::endl;
	
	if (bsp(Point(10, 0), Point(30, 30), Point(50, 0), Point(50, 15)))
		std::cout << "P is inside the triangle" << std::endl;
	else
		std::cout << "P is outside the triangle" << std::endl;

	return (0);
}
