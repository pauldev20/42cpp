/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:50:15 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 02:34:45 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

AMateria::AMateria(std::string const &type) : _type(type)
{
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	if (this != &rhs)
	{
		// this->_type = rhs._type;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             Getters And Setters                            */
/* -------------------------------------------------------------------------- */

std::string const &AMateria::getType() const
{
	return (this->_type);
}

void	AMateria::use(ICharacter &target)
{
	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}
