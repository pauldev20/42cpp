/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:59:14 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/08 01:59:34 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Cure::Cure(void) : AMateria("cure")
{
}

Cure::Cure(Cure const &src) : AMateria("cure")
{
	*this = src;
}

Cure::~Cure(void)
{
}

Cure	&Cure::operator=(Cure const &rhs)
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

AMateria	*Cure::clone(void) const
{
	return (new Cure(*this));
}

void		Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
