/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:25:27 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/13 19:22:17 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	newZombie(std::string name);
void	randomChump(std::string name);

int	main(void)
{
	Zombie zombie1("Fred");
	zombie1.announce();

	Zombie	*zombie = newZombie("Eddie");
	zombie->announce();
	delete zombie;

	randomChump("Random Zombie");

	return (0);
}
