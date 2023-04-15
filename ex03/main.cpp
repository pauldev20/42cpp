/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:21:49 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 23:12:56 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "Character.hpp"
#include "AMateria.hpp"
#include "Ice.hpp"
#include "Cure.hpp"

int main() {
	{
		ICharacter* me = new Character("me");
		AMateria* i = new Ice();

		std::cout << i->getType() << std::endl;
		AMateria* c = new Cure();
		*i = *c;
		std::cout << i->getType() << std::endl;
		i->use(*me);

		delete i;
		delete c;
		delete me;
	}

	std::cout << std::endl;

	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		ICharacter* bob = new Character("boby");

		me->use(0, *bob);
		me->use(1, *bob);

		delete bob;
		delete me;
		delete src;
	}

	std::cout << std::endl;

	{
		IMateriaSource* src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter* me = new Character("me");

		AMateria* tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);

		me->unequip(0);

		delete me;
		delete src;
	}

	std::cout << std::endl;

	{
		Character* me = new Character("me");
		me->equip(new Ice());
		me->equip(new Cure());

		Character* bob = new Character("boby");
		bob->equip(new Cure());
		*bob = *me;

		bob->use(0, *me);

		delete me;
		delete bob;
	}

	return 0;
}
