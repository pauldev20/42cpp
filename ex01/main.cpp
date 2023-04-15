/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:34:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 13:28:48 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	delete j;
	delete i;

	std::cout << std::endl;
	
	Animal* animals[10];
	for (int v = 0; v < 5; v++)
	{
		animals[v] = new Dog();
		animals[5 + v] = new Cat();
	}
	for (int v = 0; v < 10; v++)
		delete animals[v];

	std::cout << std::endl;

	{
		Dog test;
		Dog tmp;
		tmp = test;
		// Dog	tmp2(test);

		tmp.makeSound();
		// tmp2.makeSound();
    }

	std::cout << std::endl;

	return (0); 
}
