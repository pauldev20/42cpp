/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:50:15 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 19:50:46 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

AMateria::AMateria(void) : _type("AMateria")
{
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(std::string const &type) : _type(type)
{
	// std::cout << "AMateria constructor called" << std::endl;
}

AMateria::AMateria(AMateria const &src)
{
	*this = src;
}

AMateria::~AMateria(void)
{
	// std::cout << "AMateria destructor called" << std::endl;
}

AMateria	&AMateria::operator=(AMateria const &rhs)
{
	// if (this != &rhs)
	// 	this->_type = rhs._type;
	(void)rhs;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             Getters And Setters                            */
/* -------------------------------------------------------------------------- */

/**
 * The function returns a constant reference to the type of the AMateria object.
 * 
 * @return A constant reference to the `_type` member variable of the `AMateria` class.
 */
std::string const &AMateria::getType() const
{
	return (this->_type);
}

/**
 * The use function of the AMateria class prints a message indicating that the material has been used
 * on a target character.
 * 
 * @param target The parameter "target" is a reference to an object of type "ICharacter", which
 * represents the character on which the AMateria object is being used.
 */
void	AMateria::use(ICharacter &target)
{
	std::cout << "AMateria " << this->_type << " used on " << target.getName() << std::endl;
}
