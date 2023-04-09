/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:37:38 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/07 19:52:32 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

AAnimal::AAnimal(void) : type("AAnimal")
{
	std::cout << "Animal constructor called" << std::endl;
}

AAnimal::AAnimal(AAnimal const &src)
{
	std::cout << "Animal copy constructor called" << std::endl;
	*this = src;
}

AAnimal	&AAnimal::operator=(AAnimal const &rhs)
{
	std::cout << "Animal assignation operator called" << std::endl;
	this->type = rhs.type;
	return (*this);
}

AAnimal::~AAnimal(void)
{
	std::cout << "Animal destructor called" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * This function returns the type of an animal as a string.
 * 
 * @return A reference to a string object representing the type of the animal.
 */
std::string		AAnimal::getType(void) const
{
	return (this->type);
}
