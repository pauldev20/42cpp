/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:40:56 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 13:54:54 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

ScavTrap::ScavTrap() : ClapTrap()
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << this->_name << " created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
	std::cout << "ScavTrap " << this->_name << " created!" << std::endl;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->_name << " destroyed!" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The ScavTrap attacks a target and reduces its energy points.
 * 
 * @param target The target parameter is a constant reference to a string that represents the name of
 * the target that the ScavTrap object is attacking.
 * 
 * @return If the ScavTrap doesn't have any more energy, the function returns without performing the
 * attack. Otherwise, the ScavTrap attacks and a message is printed.
 */
void	ScavTrap::attack(const std::string &target)
{
	if (this->_energy_points <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " doesn't have any more energy!" << std::endl;
		return;
	}
	this->_energy_points -= 1;
	std::cout << "ScavTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

/**
 * The function "guardGate" sets the ScavTrap object into gate keeper mode if it has hit points
 * remaining.
 * 
 * @return If the ScavTrap's hit points are less than or equal to 0, the function returns without doing
 * anything. Otherwise, it prints a message indicating that the ScavTrap is now in Gate keeper mode. No
 * value is explicitly returned from the function.
 */
void	ScavTrap::guardGate()
{
	if (this->_hit_points <= 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't interact anymore!" << std::endl;
		return ;
	}
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}
