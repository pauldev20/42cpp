/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:31:02 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 13:46:40 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	claptrap("Bill");
	ClapTrap	claptrap2(claptrap);

	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.attack("target");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);
	claptrap.takeDamage(10);
	claptrap.takeDamage(10);

	return (0);
}
