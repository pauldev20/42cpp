/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:39:27 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/25 14:13:22 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(Serializer const &src)
{
	*this = src;
}

Serializer		&Serializer::operator=(Serializer const &rhs)
{
	(void)rhs;
	return (*this);
}

Serializer::~Serializer()
{
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function returns the memory address of a Data object as an unsigned integer.
 * 
 * @param ptr ptr is a pointer to an object of type Data that needs to be serialized. The function
 * returns the memory address of the object as an unsigned integer of type uintptr_t.
 * 
 * @return the memory address of the `Data` object passed as a parameter, casted to an unsigned integer
 * type `uintptr_t`. This is a way to serialize the object, as the memory address can be used to
 * reconstruct the object later.
 */
uintptr_t		Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

/**
 * The function deserializes a raw pointer into a Data object.
 * 
 * @param raw The parameter "raw" is a uintptr_t type variable which is a unsigned integer type that is
 * capable of storing a pointer value as an integer. In this code snippet, the pointer value is being
 * casted to a Data* type and returned.
 * 
 * @return a pointer to a `Data` object that has been cast from a `uintptr_t` value.
 */
Data*			Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
