/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:52:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 15:20:57 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat		*test;

	try
	{
		test = new Bureaucrat("test", 151);
		std::cout << test << std::endl;
		delete test;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test = new Bureaucrat("test", 0);
		std::cout << test << std::endl;
		delete test;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test = new Bureaucrat("test", 1);
		std::cout << *test;
		delete test;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test = new Bureaucrat("test", 150);
		std::cout << *test;
		delete test;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test = new Bureaucrat("test", 42);
		std::cout << *test;
		delete test;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}