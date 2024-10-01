/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:26:17 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 13:58:07 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

FragTrap::FragTrap() : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap " << this->_name << " created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap " << this->_name << " created!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->_name << " destroyed!" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function allows a FragTrap object to give high fives to other characters, but only if it has not
 * run out of hit points.
 * 
 * @return If the FragTrap's hit points are less than or equal to 0, the function returns without
 * performing any action. Otherwise, the function prints a message indicating that the FragTrap is
 * high-fiving guys. No value is explicitly returned by the function.
 */
void	FragTrap::highFivesGuys()
{
	if (this->_hit_points <= 0)
	{
		std::cout << "FragTrap " << this->_name << " can't interact anymore!" << std::endl;
		return ;
	}
	std::cout << "FragTrap " << this->_name << " high five guys!" << std::endl;
}
