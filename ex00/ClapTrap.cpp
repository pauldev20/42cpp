/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:23:06 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/29 01:21:54 by pgeeser          ###   ########.fr       */
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
