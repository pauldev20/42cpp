/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:31:02 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 14:09:36 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	fragtrap("John");
	FragTrap	fragtrap2(fragtrap);

	fragtrap.attack("target");
	fragtrap.takeDamage(10);
	fragtrap.beRepaired(5);
	fragtrap.highFivesGuys();
	fragtrap.takeDamage(100);
	fragtrap.highFivesGuys();

	return (0);
}
