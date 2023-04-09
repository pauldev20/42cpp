/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:34:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/07 19:48:08 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	AAnimal* animals[100];
	for (int i = 0; i < 50; i++)
	{
		animals[i] = new Dog();
		animals[50 + i] = new Cat();
	}

	// const AAnimal* meta = new AAnimal();
	const AAnimal* j = new Dog();
	const AAnimal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound! 
	j->makeSound();
    // meta->makeSound();

	const WrongAnimal* wrong_meta = new WrongAnimal();
	const WrongAnimal* wrong_i = new WrongCat();

	std::cout << wrong_i->getType() << " " << std::endl;
	wrong_i->makeSound();
	wrong_meta->makeSound();

	delete j;
	delete i;
	
	for (int i = 0; i < 100; i++)
		delete animals[i];

	system("leaks animals");

	return (0); 
}
