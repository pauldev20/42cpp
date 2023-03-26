/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:25:02 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/25 23:47:46 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * It creates a Zombie object, sets its name, and then calls its announce() function
 * 
 * @param name The name of the zombie.
 */
void	randomChump(std::string name)
{
	Zombie	zombie = Zombie(name);

	zombie.announce();
}
