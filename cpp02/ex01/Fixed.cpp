/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:07:30 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 00:55:23 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>

#include "Fixed.hpp"

/* -------------------------------------------------------------------------- */
/*                           Statics Initialization                           */
/* -------------------------------------------------------------------------- */

const int	Fixed::_fractionalBits = 8;

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * It initializes the _value member variable to 0
 */
Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

/**
 * It takes an integer as a parameter, shifts it to the left by the number of bits in the fractional
 * part, and assigns it to the _value member
 * 
 * @param value The value to be stored in the Fixed object.
 */
Fixed::Fixed(int const value) : _value(value << Fixed::_fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

/**
 * It takes a float as a parameter, multiplies it by 2 to the power
 * of _fractionalBits ( 2 * 8 = 256), and rounds it to the
 * nearest integer
 * 
 * @param value The value to be stored in the Fixed object.
 */
Fixed::Fixed(float const value) : _value(roundf(value * (1 << Fixed::_fractionalBits)))
{
	std::cout << "Float constructor called" << std::endl;
}

/**
 * It copies the value of the parameter into the object that calls it
 * 
 * @param src The object to be copied.
 */
Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

/**
 * The copy assignment operator is called when an already initialized object is assigned a new value
 * from another existing object.
 * 
 * @return A reference to the object that was assigned to.
 */
Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs._value;
	return *this;
}

/**
 * The destructor is called when the object is destroyed
 */
Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator Overloads                             */
/* -------------------------------------------------------------------------- */

/**
 * It takes a reference to an ostream object and a reference to a Fixed object, and returns a reference
 * to an ostream object
 * 
 * @return The value of the object.
 */
std::ostream &operator<<(std::ostream &os, Fixed const &person)
{
	os << person.toFloat();
	return os;
}

/* -------------------------------------------------------------------------- */
/*                             Getters and Setters                            */
/* -------------------------------------------------------------------------- */

/**
 * It returns the value of the _value member variable
 * 
 * @return The value of the fixed point value.
 */
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

/**
 * It sets the value of the Fixed object to the value of the parameter.
 * 
 * @param raw the raw value of the fixed point number.
 */
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * It returns the value of the fixed point number as a float
 * 
 * @return The value of the fixed point number as a float.
 */
float	Fixed::toFloat(void) const
{
	return (float)this->_value / (1 << Fixed::_fractionalBits);
}

/**
 * It returns the integer value of the fixed point value
 * 
 * @return The value of the fixed point number.
 */
int		Fixed::toInt(void) const
{
	return this->_value >> Fixed::_fractionalBits;
}
