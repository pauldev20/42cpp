/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:34:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 22:55:34 by pgeeser          ###   ########.fr       */
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
	
	{
		const AAnimal* j = new Dog();
		const AAnimal* i = new Cat();
		
		delete j;
		delete i;
	}

	std::cout << std::endl;
	
	{
		int	testcases = 10;
		AAnimal* animals[testcases];
		for (int v = 0; v < (testcases / 2); v++)
		{
			animals[v] = new Dog();
			animals[(testcases / 2) + v] = new Cat();
		}
		for (int v = 0; v < testcases; v++)
			delete animals[v];
	}

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

	std::cout << std::endl;

	{
		Dog *test = new Dog();
		Dog tmp;
		tmp = *test;
		delete test;

		tmp.makeSound();
	}

	std::cout << std::endl;

	{
		Cat *test = new Cat();
		Cat tmp;
		tmp = *test;
		delete test;

		tmp.makeSound();
	}

	return (0); 
}
