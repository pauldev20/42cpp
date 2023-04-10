/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:38:06 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/10 19:50:42 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Span::Span() : _size(0), _pos(0)
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
	return (*this)
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

void 	Span::addNumber(int nb)
{
	if (this->_pos >= this->_size)
		throw Span::TooManyElementsException();
	this->_vec.push_back(nb);
	this->_pos++;
}

int		Span::longestSpan(void) const
{
	return (*std::max_element(this->_vec.begin(), this->_vec.end()).base());
}

int		Span::shortestSpan(void) const
{
	return (*std::min_element(this->_vec.begin(), this->_vec.end()).base());
}

/* -------------------------------------------------------------------------- */
/*                                 Excpetions                                 */
/* -------------------------------------------------------------------------- */

const char *Span::TooManyElementsException::what() const throw()
{
	return ("Array Is Full");
}
