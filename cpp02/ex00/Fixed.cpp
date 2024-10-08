/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:07:30 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 00:15:33 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* -------------------------------------------------------------------------- */
/*                           Statics Initialization                           */
/* -------------------------------------------------------------------------- */

const int	Fixed::_fractionalBits = 8;

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Fixed::Fixed() : _value(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const &src)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                             Operator Overloads                             */
/* -------------------------------------------------------------------------- */

Fixed	&Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->_value = rhs.getRawBits();
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                             Getters and Setters                            */
/* -------------------------------------------------------------------------- */

/**
 * The function returns the raw value of a Fixed object and prints a message to the console.
 * 
 * @return the value of the private member variable `_value`, which represents the fixed-point value in
 * its raw binary form.
 */
int		Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

/**
 * This function sets the raw value of a Fixed object.
 * 
 * @param raw raw is an integer value that represents the raw value of a fixed-point number. In a
 * fixed-point number representation, the value is stored as an integer, but it is interpreted as a
 * fixed-point number with a certain number of fractional bits. The setRawBits function sets the raw
 * value of the fixed
 */
void	Fixed::setRawBits(int const raw)
{
	this->_value = raw;
}
