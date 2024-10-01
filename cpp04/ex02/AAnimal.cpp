/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:37:38 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/07 18:18:36 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "AAnimal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "AAnimal copy constructor called" << std::endl;
	*this = src;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "AAnimal assignation operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * This function returns the type of an AAnimal as a string.
 * 
 * @return A reference to a string object representing the type of the AAnimal.
 */
std::string		AAnimal::getType(void) const
{
	return (this->type);
}

/**
 * The function "makeSound" outputs "AAnimal sound" to the console.
 */
void			AAnimal::makeSound(void) const
{
	std::cout << "AAnimal sound" << std::endl;
}
