/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:34:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 22:39:42 by pgeeser          ###   ########.fr       */
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
		const Animal* meta = new Animal();
		const Animal* j = new Dog();
		const Animal* i = new Cat();

		std::cout << j->getType() << " " << std::endl;
		std::cout << i->getType() << " " << std::endl;
		i->makeSound(); //will output the cat sound! 
		j->makeSound();
		meta->makeSound();

		delete meta;
		delete i;
		delete j;
	}

	std::cout << std::endl;

	{
		const WrongAnimal* wrong_meta = new WrongAnimal();
		const WrongAnimal* wrong_i = new WrongCat();

		std::cout << wrong_i->getType() << " " << std::endl;
		wrong_i->makeSound();
		wrong_meta->makeSound();

		delete wrong_meta;
		delete wrong_i;
	}

	std::cout << std::endl;

	{
		Dog	test;
		Dog tmp(test);
		
		tmp.makeSound();
	}

	std::cout << std::endl;

	{
		WrongCat wrong_test;
		WrongCat wrong_tmp(wrong_test);
		
		wrong_tmp.makeSound();	
	}
	
	return (0); 
}
