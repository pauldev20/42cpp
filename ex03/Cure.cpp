/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:59:14 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 19:50:38 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Cure::Cure(void) : AMateria("cure")
{
	// std::cout << "Cure constructor called" << std::endl;
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
	*this = src;
}

Cure::~Cure(void)
{
	// std::cout << "Cure destructor called" << std::endl;
}

Cure	&Cure::operator=(Cure const &rhs)
{
	(void)rhs;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function returns a new instance of the Cure class by cloning the current instance.
 * 
 * @return A pointer to a new instance of the Cure class, which is a copy of the current instance.
 */
AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

/**
 * The function "use" of the "Cure" class heals the wounds of the target character.
 * 
 * @param target The parameter "target" is a reference to an object of type "ICharacter", which
 * represents the character that the Cure object is being used on.
 */
void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
