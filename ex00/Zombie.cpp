/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:16:53 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/25 23:24:59 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Zombie::Zombie(std::string name) : _name(name)
{
	std::cout << this->_name << ": I'm alive" << std::endl;
}

Zombie::~Zombie(void)
{
	std::cout << this->_name << ": Oh no I'm dying" << std::endl;
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
