/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:38:06 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/26 20:59:30 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <limits>	// std::numeric_limits

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Span::Span(void) : _size(0), _pos(0)
{
}

Span::Span(unsigned int N) : _size(N), _pos(0)
{
	this->_vec.reserve(N);
}

Span::Span(Span const &src)
{
	*this = src;
}

Span::~Span(void)
{
}

Span	&Span::operator=(Span const &rhs)
{
	(void)rhs;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function adds a number to a vector and throws an exception if the vector is already full.
 * 
 * @param nb nb is an integer value that represents the number to be added to the Span object's vector.
 */
void 	Span::addNumber(int nb)
{
	if (this->_pos >= this->_size)
		throw Span::TooManyElementsException();
	this->_vec.push_back(nb);
	this->_pos++;
}

/**
 * This function calculates the longest span between any two elements in a vector.
 * 
 * @return The function `longestSpan` is returning the largest absolute difference between any two
 * elements in the `_vec` vector.
 */
int		Span::longestSpan(void) const
{
	if (this->_size < 2)
		throw Span::NoSpanCanBeFoundException();
	int biggest_span = std::numeric_limits<int>::min();
	for (unsigned long i = 0; i < this->_vec.size(); i++) {
		for (unsigned long j = i + 1; j < this->_vec.size(); j++) {
			int span = ABS(this->_vec[i] - this->_vec[j]);
			if (span > biggest_span)
                biggest_span = span;
		}
	}
	return (biggest_span);
}

/**
 * This function calculates the shortest span between any two elements in a vector.
 * 
 * @return The function `shortestSpan` is returning the shortest span between any two integers in the
 * `_vec` vector.
 */
int		Span::shortestSpan(void) const
{
	if (this->_size < 2)
		throw Span::NoSpanCanBeFoundException();
	int shortest_span = std::numeric_limits<int>::max();
	for (unsigned long i = 0; i < this->_vec.size(); i++) {
		for (unsigned long j = i + 1; j < this->_vec.size(); j++) {
			int span = ABS(this->_vec[i] - this->_vec[j]);
			if (span < shortest_span)
                shortest_span = span;
		}
	}
	return (shortest_span);
}

/* -------------------------------------------------------------------------- */
/*                                 Excpetions                                 */
/* -------------------------------------------------------------------------- */

const char *Span::TooManyElementsException::what() const throw()
{
	return ("Array Is Full");
}

const char *Span::NoSpanCanBeFoundException::what() const throw()
{
	return ("No Span Can Be Found (No Elements or Not Enough Elements)");
}

