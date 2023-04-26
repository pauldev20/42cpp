/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:44:02 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/26 02:51:42 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>

int	main(void)
{
	{
		MutantStack<std::string> test;
		test.push("string1");
		test.push("string2");
		test.push("string3");
		test.push("string4");

		MutantStack<std::string>::iterator sit = test.begin();
		MutantStack<std::string>::iterator eit = test.end();
		while (sit != eit)
			std::cout << *sit++ << std::endl;
	}

	std::cout << std::endl;

	{
		MutantStack<int> test;
		test.push(1);
		test.push(2);
		test.push(3);
		test.push(4);

		MutantStack<int>::iterator sit = test.begin();
		MutantStack<int>::iterator eit = test.end();
		while (sit != eit)
			std::cout << *sit++ << std::endl;
	}

	return (0);
}
