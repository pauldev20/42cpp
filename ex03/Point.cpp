/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 02:59:01 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/28 03:07:53 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * It's a constructor that initializes the _x and _y attributes to Fixed() (which is the default
 * constructor)
 */
Point::Point() : _x(Fixed()), _y(Fixed())
{
}

/**
 * It takes two Fixed objects as parameters and assigns them to the _x and _y attributes of the object
 * 
 * @param x The x coordinate of the point.
 * @param y The y coordinate of the point.
 */
Point::Point(Fixed const &x, Fixed const &y) : _x(x), _y(y)
{
}

/**
 * The copy constructor is a constructor which creates an object by initializing it with an object of
 * the same class, which has been created previously.
 * 
 * @param src The object to be copied.
 */
Point::Point(Point const &src) : _x(src._x), _y(src._y)
{
}

/**
 * If the object on the left hand side of the assignment operator is not the same as the object on the
 * right hand side of the assignment operator, then copy the right hand side object into the left hand
 * side object.
 * 
 * @return A reference to the object that called the function.
 */
Point &Point::operator=(Point const &rhs)
{
	if (this != &rhs) {
		(Fixed) this->_x = rhs.getX();
		(Fixed) this->_y = rhs.getY();
	}
	return *this;
}

/**
 * The destructor is called when the object is destroyed
 */
Point::~Point()
{
}

/* -------------------------------------------------------------------------- */
/*                             Getters and Setters                            */
/* -------------------------------------------------------------------------- */

/**
 * GetX returns the value of the private member _x.
 * 
 * @return A reference to the x coordinate of the point.
 */
Fixed const &Point::getX(void) const
{
	return this->_x;
}

/**
 * GetY returns the y coordinate of the point
 * 
 * @return A reference to the y coordinate of the point.
 */
Fixed const &Point::getY(void) const
{
	return this->_y;
}
