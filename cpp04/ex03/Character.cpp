/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:00:36 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 20:02:07 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Character::Character(std::string const &name) : _name(name)
{
	for (int i = 0; i < 100; i++)
		this->_floor[i] = NULL;
	for (int i = 0; i < 4; i++)
		this->_inventory[i] = NULL;
}

Character::Character(Character const &src)
{
	*this = src;
}

Character::~Character(void)
{
	for (int i = 0; i < 100; i++) {
		if (this->_floor[i] != NULL) {
			delete this->_floor[i];
			this->_floor[i] = NULL;
		}
	}
	for (int i = 0; i < 4; i++)
		if (this->_inventory[i] != NULL)
			delete this->_inventory[i];
}

Character	&Character::operator=(Character const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_inventory[i] != NULL)
				delete this->_inventory[i];
			if (rhs._inventory[i] != NULL)
				this->_inventory[i] = rhs._inventory[i]->clone();
			else
				this->_inventory[i] = NULL;
		}
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             Getters And Setters                            */
/* -------------------------------------------------------------------------- */

std::string const	&Character::getName() const
{
	return (this->_name);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function equips a given AMateria object to the Character's inventory or floor if there is no
 * space in the inventory.
 * 
 * @param m m is a pointer to an AMateria object that represents the material to be equipped by the
 * Character.
 * 
 * @return If the inventory has an empty slot, the function will return without any value. If the
 * inventory is full and the given materia is not NULL, it will be added to the floor and the function
 * will return without any value.
 */
void				Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++) {
		if (this->_inventory[i] == NULL) {
			this->_inventory[i] = m;
			return ;
		}
	}
	if (m == NULL)
		return ;
	int		idx = 0;
	while (this->_floor[idx] != NULL)
		idx++;
	this->_floor[idx] = m;
}

/**
 * The function unequips an item from the character's inventory and places it on the floor.
 * 
 * @param idx idx is an integer parameter representing the index of the item to be unequipped from the
 * character's inventory. It should be a value between 0 and 3.
 * 
 * @return If the value of `idx` is less than 0 or greater than 3, the function returns nothing
 * (`void`).
 */
void				Character::unequip(int idx)
{
	if (idx < 0 || idx > 3)
		return ;
	int		id = 0;
	while (this->_floor[id] != NULL)
		id++;
	this->_floor[id] = this->_inventory[idx];
	this->_inventory[idx] = NULL;
}

/**
 * The use function of the Character class checks if the inventory slot is valid and uses the item on
 * the target if it exists.
 * 
 * @param idx idx is an integer parameter representing the index of the item in the character's
 * inventory that the character wants to use.
 * @param target target is a reference to an object of type ICharacter, which is the character that the
 * current character is using the item on.
 * 
 * @return If the `idx` parameter is less than 0 or greater than 3, the function returns without doing
 * anything. If the `_inventory` array at the specified index is not `NULL`, the `use` function of the
 * object at that index is called with the `target` parameter. No value is explicitly returned by the
 * function.
 */
void				Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx > 3)
		return ;
	if (this->_inventory[idx] != NULL)
		this->_inventory[idx]->use(target);
}
