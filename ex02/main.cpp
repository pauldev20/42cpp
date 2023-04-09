/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:09:22 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 18:49:22 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	Bureaucrat		*test;
	Form 			*form;

	try
	{
		test = new Bureaucrat("test1", 1);
		std::cout << *test;
		form = new PresidentialPardonForm("default");
		test->signForm(*form);
		form->execute(*test);
		delete test;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test = new Bureaucrat("test1", 1);
		std::cout << *test;
		form = new PresidentialPardonForm("default");
		form->execute(*test);
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
		test = new Bureaucrat("test1", 1);
		std::cout << *test;
		form = new RobotomyRequestForm("default");
		form->execute(*test);
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
		test = new Bureaucrat("test1", 1);
		std::cout << *test;
		form = new RobotomyRequestForm("default");
		test->signForm(*form);
		form->execute(*test);
		delete test;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test = new Bureaucrat("test1", 1);
		std::cout << *test;
		form = new RobotomyRequestForm("default");
		test->signForm(*form);
		form->execute(*test);
		delete test;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test = new Bureaucrat("test1", 1);
		std::cout << *test;
		form = new RobotomyRequestForm("default");
		test->signForm(*form);
		form->execute(*test);
		delete test;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		test = new Bureaucrat("test1", 1);
		std::cout << *test;
		form = new ShrubberyCreationForm("default");
		test->signForm(*form);
		form->execute(*test);
		delete test;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}