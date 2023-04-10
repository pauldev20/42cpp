/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:53:18 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/10 15:26:50 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Identifier.hpp"

int main(void)
{
	Base *test;	

	std::srand(std::time(nullptr));
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
