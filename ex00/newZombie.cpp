/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newZombie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:24:37 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/25 23:24:52 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

/**
 * This function creates a new Zombie object and returns a pointer to it.
 * 
 * @param name the name of the zombie
 * 
 * @return A pointer to a Zombie object.
 */
Zombie*	newZombie(std::string name)
{
	Zombie	*zombie = new Zombie(name);
	return (zombie);
}
