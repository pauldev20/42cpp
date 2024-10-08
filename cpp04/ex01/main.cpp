/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:34:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 22:54:47 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal* j = new Dog();
		const Animal* i = new Cat();
		
		delete j;
		delete i;
	}

	std::cout << std::endl;
	
	{
		int	testcases = 10;
		Animal* animals[testcases];
		for (int v = 0; v < (testcases / 2); v++)
		{
			animals[v] = new Dog();
			animals[(testcases / 2) + v] = new Cat();
		}
		for (int v = 0; v < testcases; v++)
			delete animals[v];
	}

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
