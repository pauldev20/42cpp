/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:07:30 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 00:36:01 by pgeeser          ###   ########.fr       */
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
}

/**
 * It takes an integer as a parameter, shifts it to the left by the number of bits in the fractional
 * part, and assigns it to the _value member
 * 
 * @param value The value to be stored in the Fixed object.
 */
Fixed::Fixed(int const value) : _value(value << Fixed::_fractionalBits)
{
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
}

/**
 * It copies the value of the parameter into the object that calls it
 * 
 * @param src The object to be copied.
 */
Fixed::Fixed(Fixed const &src)
{
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
	this->_value = rhs.getRawBits();
	return *this;
}

/**
 * The destructor is called when the object is destroyed
 */
Fixed::~Fixed()
{
}

/* -------------------------------------------------------------------------- */
/*                             Operator Overloads                             */
/* -------------------------------------------------------------------------- */

/**
 * It compares the value of the object to the value of the object passed as a parameter.
 * 
 * @param rhs The right hand side of the comparison.
 * 
 * @return A boolean value.
 */
bool	Fixed::operator>(Fixed const &rhs) const
{
	return this->_value > rhs.getRawBits();
}

/**
 * It compares the value of the object to the value of the object passed as a parameter.
 * 
 * @param rhs The right hand side of the comparison.
 * 
 * @return A boolean value.
 */
bool	Fixed::operator<(Fixed const &rhs) const
{
	return this->_value < rhs.getRawBits();
}

/**
 * It compares the value of the object to the value of the object passed as a parameter.
 * 
 * @param rhs The right hand side of the equation.
 * 
 * @return A boolean value.
 */
bool	Fixed::operator>=(Fixed const &rhs) const
{
	return this->_value >= rhs.getRawBits();
}

/**
 * It compares the value of the object to the value of the object passed as a parameter.
 * 
 * @param rhs The right hand side of the comparison.
 * 
 * @return A boolean value.
 */
bool	Fixed::operator<=(Fixed const &rhs) const
{
	return this->_value <= rhs.getRawBits();
}

/**
 * It compares the value of the object to the value of the object passed as a parameter.
 * 
 * @param rhs The right hand side of the equation.
 * 
 * @return A boolean value.
 */
bool	Fixed::operator==(Fixed const &rhs) const
{
	return this->_value == rhs.getRawBits();
}

/**
 * It compares the value of the object to the value of the object passed as a parameter.
 * 
 * @param rhs The right hand side of the equation.
 * 
 * @return A boolean value.
 */
bool	Fixed::operator!=(Fixed const &rhs) const
{
	return this->_value != rhs.getRawBits();
}

/**
 * This function returns a Fixed object that is the result of adding the value of the current object to
 * the value of the object passed as a parameter.
 * 
 * @param rhs The right hand side of the equation.
 * 
 * @return A new instance of Fixed with the result of the addition.
 */
Fixed	Fixed::operator+(Fixed const &rhs) const
{
	return Fixed(this->toFloat() + rhs.toFloat());
}

/**
 * It returns a new Fixed object that is the result of subtracting the value of the parameter from the
 * value of the object on which the function is called.
 * 
 * @param rhs The right hand side of the equation.
 * 
 * @return A new instance of Fixed with the result of the operation.
 */
Fixed	Fixed::operator-(Fixed const &rhs) const
{
	return Fixed(this->toFloat() - rhs.toFloat());
}

/**
 * It returns a new Fixed object that is the result of multiplying the current object by the parameter.
 * 
 * @param rhs The right hand side of the multiplication.
 * 
 * @return A new instance of Fixed with the result of the operation.
 */
Fixed	Fixed::operator*(Fixed const &rhs) const
{
	return Fixed(this->toFloat() * rhs.toFloat());
}

/**
 * It returns a new Fixed object that is the result of dividing the current object by the parameter.
 * 
 * @param rhs The right hand side of the equation.
 * 
 * @return A new instance of Fixed with the result of the division.
 */
Fixed	Fixed::operator/(Fixed const &rhs) const
{
	return Fixed(this->toFloat() / rhs.toFloat());
}

/**
 * It increments the value of the Fixed object by 1
 * 
 * @return A reference to the current object.
 */
Fixed	&Fixed::operator++(void)
{
	this->_value++;
	return *this;
}

/**
 * Decrement the value of the fixed point value by 1
 * 
 * @return A reference to the object that was operated on.
 */
Fixed	&Fixed::operator--(void)
{
	this->_value--;
	return *this;
}

/**
 * It creates a temporary copy of the current object, increments the current object, and returns the
 * temporary copy.
 * 
 * @param  `int`: This is a dummy parameter. It's not used in the function, but it's required to
 * differentiate between prefix and postfix increment.
 * 
 * @return A copy of the object before the increment.
 */
Fixed	Fixed::operator++(int)
{
	Fixed tmp(*this);
	this->_value++;
	return tmp;
}

/**
 * It creates a temporary copy of the current object, decrements the current object, and returns the
 * temporary copy.
 * 
 * @param  `int`: This is the number of bits that will be used to store the fractional part of the
 * number.
 * 
 * @return A copy of the object before the operation.
 */
Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	this->_value--;
	return tmp;
}

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

/**
 * Return the minimum of two Fixed objects.
 * 
 * @return A reference to the smaller of the two values.
 */
Fixed	&Fixed::min(Fixed &a, Fixed &b)
{
	return a < b ? a : b;
}

/**
 * Return the minimum of two Fixed objects.
 * 
 * @return A reference to the object that is the smaller of the two.
 */
Fixed const	&Fixed::min(Fixed const &a, Fixed const &b)
{
	return a < b ? a : b;
}

/**
 * Return the larger of two Fixed objects.
 * 
 * @return A reference to the larger of the two values.
 */
Fixed	&Fixed::max(Fixed &a, Fixed &b)
{
	return a > b ? a : b;
}

/**
 * Return the greater of two Fixed objects.
 * 
 * @return A reference to the object that is the greater of the two.
 */
Fixed const	&Fixed::max(Fixed const &a, Fixed const &b)
{
	return a > b ? a : b;
}
