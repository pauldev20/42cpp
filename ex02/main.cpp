/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:31:02 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/29 01:31:44 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	ClapTrap	claptrap("Bill");
	ClapTrap	claptrap2(claptrap);

	claptrap.attack("target");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);

	ScavTrap	scavtrap("John");
	ScavTrap	scavtrap2(scavtrap);

	scavtrap.attack("target");
	scavtrap.takeDamage(10);
	scavtrap.beRepaired(5);
	scavtrap.guardGate();

	FragTrap	fragtrap("John");
	FragTrap	fragtrap2(fragtrap);

	fragtrap.attack("target");
	fragtrap.takeDamage(10);
	fragtrap.beRepaired(5);
	fragtrap.highFivesGuys();
	return (0);
}