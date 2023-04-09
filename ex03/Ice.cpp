/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:56:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 02:18:29 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Ice::Ice(void) : AMateria("ice")
{
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
	*this = src;
}

Ice::~Ice(void)
{
}

Ice	&Ice::operator=(Ice const &rhs)
{
	if (this != &rhs)
	{
		// this->_type = rhs._type;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
