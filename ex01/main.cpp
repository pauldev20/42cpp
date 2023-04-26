/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:54:35 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/26 03:23:31 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>	// std::cout, std::endl

int	main(void)
{
	{
		Span sp = Span(5);

		sp.addNumber(6);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);

		std::cout << sp.shortestSpan() << std::endl;
		std::cout << sp.longestSpan() << std::endl;
	}
	
	std::cout << std::endl;

	{
		Span	spn(30);
		for (int i = 0; i < 31; i++) {
			try {
				spn.addNumber(i);
			} catch (std::exception &exc) {
				std::cout << exc.what() << std::endl;
			}
		}
		std::cout << spn.longestSpan() << std::endl;
		std::cout << spn.shortestSpan() << std::endl;
	}
	
	std::cout << std::endl;

	{
		Span				spn(100);
		std::vector<int>	rng(100, 42);

		rng[50] = 50;
		rng[55] = 55;
		spn.addNumber(rng.begin(), rng.end());

		std::cout << spn.longestSpan() << std::endl;
		std::cout << spn.shortestSpan() << std::endl;
	}
	return (0);
}
