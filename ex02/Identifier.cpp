/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Identifier.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:50:52 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/25 14:31:43 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"
#include <iostream>			// std::cout, std::endl
#include <typeinfo>			// std::bad_cast
#include <cstdlib>			// rand()

/**
 * The function generates a random number and returns a pointer to an object of class A, B, or C based
 * on the value of the random number.
 * 
 * @return The function `generate` returns a pointer to an instance of one of three classes: `A`, `B`,
 * or `C`. The specific class instance returned is determined randomly by generating a random number
 * between 0 and 2 (inclusive) using the `rand()` function. If the random number is 0, an instance of
 * class `A` is returned. If the random number is
 */
Base	*generate(void)
{
	int	rand_num = rand() % 3;

	switch (rand_num)
	{
		case 0:
			return (new A());
		case 1:
			return (new B());
		default:
			return (new C());
	}
}

/**
 * The function identifies the class type of a given pointer using dynamic casting in C++.
 * 
 * @param p The parameter "p" is a pointer to a Base class object.
 */
void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	else if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	else if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
	else
		std::cout << "Unknown Class" << std::endl;
}

/**
 * The function identifies the derived class of a given object by attempting to cast it to each
 * possible derived class and printing the corresponding class name or "Unknown Class" if the cast
 * fails.
 * 
 * @param p The parameter "p" is a reference to an object of the class "Base".
 * 
 * @return The function is not returning anything. It is using the `std::cout` statement to print out
 * the type of the object that is being passed as a reference to the `identify` function. If the object
 * is of type `A`, the function prints "A". If the object is of type `B`, the function prints "B". If
 * the object is of type `C`, the function
 */
void	identify(Base& p)
{
	try {
		(void)dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		return;
	} catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		return;
	} catch (std::bad_cast &e) {}
	try {
		(void)dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		return;
	} catch (std::bad_cast &e) {}
	std::cout << "Unknown Class" << std::endl;
}
