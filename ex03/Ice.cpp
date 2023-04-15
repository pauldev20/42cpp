/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:56:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 19:50:55 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Ice::Ice(void) : AMateria("ice")
{
	// std::cout << "Ice constructor called" << std::endl;
}

Ice::Ice(Ice const &src) : AMateria("ice")
{
	*this = src;
}

Ice::~Ice(void)
{
	// std::cout << "Ice destructor called" << std::endl;
}

Ice	&Ice::operator=(Ice const &rhs)
{
	(void)rhs;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function returns a new instance of the Ice class by cloning the current instance.
 * 
 * @return A pointer to a new instance of the Ice class, which is a copy of the current instance.
 */
AMateria	*Ice::clone(void) const
{
	return (new Ice(*this));
}

/**
 * The function "use" in the "Ice" class shoots an ice bolt at a target character.
 * 
 * @param target The parameter "target" is a reference to an object of type "ICharacter", which is
 * being passed to the member function "use" of the class "Ice".
 */
void		Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
