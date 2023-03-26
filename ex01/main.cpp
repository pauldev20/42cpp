/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:34:35 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/25 23:47:38 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie*	zombieHorde(int N, std::string name);

int	main(void)
{
	Zombie	*zombies = zombieHorde(10, "Fred");

	for (int i = 0; i < 10; i++)
		zombies[i].announce();
	delete[] zombies;
	return (0);
}