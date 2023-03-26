/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:00:34 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/26 00:01:16 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Weapon::Weapon(std::string type) : _type(type)
{
}

Weapon::~Weapon(void)
{
}

/* -------------------------------------------------------------------------- */
/*                             Getters and Setters                            */
/* -------------------------------------------------------------------------- */

/**
 * It returns a reference to the type of the weapon.
 * 
 * @return A reference to the string type.
 */
std::string const	&Weapon::getType(void)
{
	return (this->_type);
}

/**
 * It sets the type of the weapon
 * 
 * @param type The type of weapon.
 */
void				Weapon::setType(std::string type)
{
	this->_type = type;
}
