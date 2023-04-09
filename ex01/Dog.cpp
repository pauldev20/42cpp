/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:45:46 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/07 19:05:48 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Dog::Dog(void) : Animal()
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog(void)
{
	delete this->brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs)
{
	this->type = rhs.type;
	this->brain = new Brain(*rhs.brain);
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function makes a dog sound by printing "Wooof Wooof" to the console.
 */
void	Dog::makeSound(void) const
{
	std::cout << "Wooof Wooof" << std::endl;
}
