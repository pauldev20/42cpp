/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 01:37:39 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 15:06:44 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

DiamondTrap::DiamondTrap() : ScavTrap(), FragTrap(), _name("default")
{
	this->ClapTrap::_name = "default_clap_name";
	this->_hit_points = 100;	// because this is wrong: FragTrap::_hit_points;
	this->_energy_points = 50;	// because this is wrong: ScavTrap::_energy_points;
	this->_attack_damage = 30;	// because this is wrong: FragTrap::_attack_damage;
	std::cout << "DiamondTrap default constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ScavTrap(name), FragTrap(name), _name(name)
{
	this->ClapTrap::_name = name.append("_clap_name");
	this->_hit_points = 100;	// because this is wrong: FragTrap::_hit_points;
	this->_energy_points = 50;	// because this is wrong: ScavTrap::_energy_points;
	this->_attack_damage = 30;	// because this is wrong: FragTrap::_attack_damage;
	std::cout << "DiamondTrap " << this->_name << " created!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap " << this->_name << " destroyed!" << std::endl;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function "whoAmI" in the DiamondTrap class prints out the name of the DiamondTrap object and its
 * ClapTrap base class.
 */
void	DiamondTrap::whoAmI()
{
	std::cout << "DiamondTrap " << this->_name << " is " << this->ClapTrap::_name << std::endl;
}
