/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 16:45:46 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 17:39:50 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(Dog const &src) : AAnimal(src)
{
	std::cout << "Dog copy constructor called" << std::endl;
	this->brain = new Brain();
	*this = src;
}

Dog::~Dog(void)
{
	std::cout << "Dog destructor called" << std::endl;
	delete this->brain;
}

Dog &Dog::operator=(Dog const &rhs)
{
	std::cout << "Dog assignation operator called" << std::endl;
	*this->brain = *rhs.brain;
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
