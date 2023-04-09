/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:52:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 15:23:17 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat		*test;
	Form			*form;

	try
	{
		test = new Bureaucrat("test", 151);
		std::cout << *test << std::endl;
		delete test;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test = new Bureaucrat("test", 0);
		std::cout << *test << std::endl;
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

	try
	{
		form = new Form("testform", 1, 1);
		test = new Bureaucrat("test", 1);
		test->signForm(*form);
		delete test;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form = new Form("testform", 2, 1);
		test = new Bureaucrat("test", 1);
		test->signForm(*form);
		delete test;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form = new Form("testform", 0, 1);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form = new Form("testform", 2, 0);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		form = new Form("testform", 300, 3);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}