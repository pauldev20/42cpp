/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:23:06 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 13:41:59 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

ClapTrap::ClapTrap() : _name("default"), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(10), _energy_points(10), _attack_damage(0)
{
	std::cout << "ClapTrap " << this->_name << " created!" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &src)
{
	*this = src;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
{
	this->_name = rhs._name;
	this->_hit_points = rhs._hit_points;
	this->_energy_points = rhs._energy_points;
	this->_attack_damage = rhs._attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->_name << " destroyed!" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The ClapTrap attacks a target and reduces its energy points.
 * 
 * @param target The target parameter is a constant reference to a string that represents the name of
 * the target that the ClapTrap object is attacking.
 * 
 * @return If the ClapTrap doesn't have any more energy, the function returns without performing the
 * attack. Otherwise, the ClapTrap attacks and a message is printed.
 */
void	ClapTrap::attack(const std::string &target)
{
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have any more energy!" << std::endl;
		return;
	}
	this->_energy_points -= 1;
	std::cout << "ClapTrap " << this->_name << " attacks " << target << ", causing " << this->_attack_damage << " points of damage!" << std::endl;
}

/**
 * The function reduces the hit points of a ClapTrap object by a specified amount and outputs a
 * message.
 * 
 * @param amount The amount of damage that the ClapTrap object will take.
 * 
 * @return If the ClapTrap doesnt have any more hit points, the function returns without doing
 * anything and printing a simple message. Otherwise, the ClapTrap's hit points are reduced by
 * the amount specified in the function parameter and a message is printed indicating how much 
 * damage was taken.
 */
void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hit_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't be hit anymore!" << std::endl;
		return;
	}
	this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount << " points of damage!" << std::endl;
}

/**
 * The ClapTrap is repaired and reduces its energy points.
 * 
 * @param amount The amount of hit points that the ClapTrap object will be repaired by.
 * 
 * @return If the ClapTrap doesn't have any more energy, the function returns without performing the
 * repair. Otherwise, the ClapTrap is repaired and a message is printed.
 */
void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_energy_points <= 0)
	{
		std::cout << "ClapTrap " << this->_name << " doesn't have any more energy!" << std::endl;
		return;
	}
	this->_energy_points -= 1;
	this->_hit_points += amount;
	std::cout << "ClapTrap " << this->_name << " repaired " << amount << " points!" << std::endl;
}
