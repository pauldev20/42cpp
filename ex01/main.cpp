/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:54:35 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/26 20:48:49 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>	// std::cout, std::endl
#include <ctime>	// std::time
#include <cstdlib>	// srand, rand

int	main(void)
{
	{
		Span sp = Span(0);

		try {
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception &exec) {
			std::cout << exec.what() << std::endl;
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &exec) {
			std::cout << exec.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		Span sp = Span(1);

		try {
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception &exec) {
			std::cout << exec.what() << std::endl;
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &exec) {
			std::cout << exec.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		Span sp = Span(2);
		sp.addNumber(5);
		sp.addNumber(1);

		try {
			std::cout << sp.shortestSpan() << std::endl;
		} catch (std::exception &exec) {
			std::cout << exec.what() << std::endl;
		}
		try {
			std::cout << sp.longestSpan() << std::endl;
		} catch (std::exception &exec) {
			std::cout << exec.what() << std::endl;
		}
	}

	std::cout << std::endl;

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

	std::cout << std::endl;

	{
		Span				spn(15000);

		srand(std::time(NULL));		
		for (int i = 0; i < 15000; i++) {
			spn.addNumber(rand());
		}

		std::cout << spn.longestSpan() << std::endl;
		std::cout << spn.shortestSpan() << std::endl;
	}

	return (0);
}
