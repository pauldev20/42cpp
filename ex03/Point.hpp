/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:55:53 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/28 03:01:44 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include "Fixed.hpp"

class Point {
	private:
		Fixed const	_x;
		Fixed const	_y;

	public:
		Point();
		Point(Fixed const &x, Fixed const &y);
		Point(Point const &src);
		Point &operator=(Point const &rhs);
		~Point();

		Fixed const &getX(void) const;
		Fixed const &getY(void) const;
};

#endif