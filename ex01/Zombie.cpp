/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:16:53 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/26 00:01:51 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Zombie::Zombie(void)
{
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": Oh no I'm dying" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                                   Setters                                  */
/* -------------------------------------------------------------------------- */

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * This function prints the name of the zombie and the string 'BraiiiiiiinnnzzzZ...' to the standard
 * output.
 */
void	Zombie::announce(void)
{
	std::cout << this->_name  << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
