/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:34:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 22:25:56 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	// AAnimal animal; // abstract class
	
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl;
	
	AAnimal* AAnimals[10];
	for (int v = 0; v < 5; v++)
	{
		AAnimals[v] = new Dog();
		AAnimals[5 + v] = new Cat();
	}
	for (int v = 0; v < 10; v++)
		delete AAnimals[v];

	std::cout << std::endl;

	{
		Dog test;
		Dog	tmp(test);
		Dog tmp2;
		tmp2 = test;

		test.makeSound();
		tmp.makeSound();
		tmp2.makeSound();
    }

	std::cout << std::endl;

	{
		Cat test;
		Cat	tmp(test);
		Cat tmp2;
		tmp2 = test;

		test.makeSound();
		tmp.makeSound();
		tmp2.makeSound();
    }

	return (0); 
}
