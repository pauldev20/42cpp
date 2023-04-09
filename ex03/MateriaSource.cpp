/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:19:05 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 02:20:10 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

MateriaSource::MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
		this->_materia[i] = NULL;
	this->_count = 0;
}

MateriaSource::MateriaSource(MateriaSource const &src)
{
	*this = src;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (this->_materia[i] != NULL)
			delete this->_materia[i];
	}
}

MateriaSource	&MateriaSource::operator=(MateriaSource const &rhs)
{
	if (this != &rhs)
	{
		for (int i = 0; i < 4; i++)
		{
			if (this->_materia[i] != NULL)
				delete this->_materia[i];
			if (rhs._materia[i] != NULL)
				this->_materia[i] = rhs._materia[i]->clone();
			else
				this->_materia[i] = NULL;
		}
		this->_count = rhs._count;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

void	MateriaSource::learnMateria(AMateria *m)
{
	if (this->_count < 4 && m != NULL)
	{
		this->_materia[this->_count] = m;
		this->_count++;
	}
}

AMateria	*MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < this->_count; i++)
	{
		if (this->_materia[i]->getType() == type)
			return (this->_materia[i]->clone());
	}
	return (NULL);
}
