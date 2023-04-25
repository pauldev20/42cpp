/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:53:18 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/25 14:31:25 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"
#include <iostream>			// std::cout, std::endl
#include <cstdlib>			// std::rand
#include <ctime>			// std::time

int main(void)
{
	Base *test;	

	std::srand(std::time(NULL));
	for (int j = 0; j < 8; j++)
	{
		std::cout << "Test " << j << std::endl;
		test = generate();
		identify(test);
		identify(*test);
		delete test;
		std::cout << std::endl;
	}

	return (0);
}
