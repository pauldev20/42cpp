/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 00:31:02 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/29 00:31:29 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	claptrap("Bill");
	ClapTrap	claptrap2(claptrap);

	claptrap.attack("target");
	claptrap.takeDamage(10);
	claptrap.beRepaired(5);
	return (0);
}