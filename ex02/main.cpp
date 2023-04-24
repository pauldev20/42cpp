/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:09:22 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/24 15:38:15 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void)
{
	{
		try
		{
			Bureaucrat test("test1", 1);
			std::cout << test;
			PresidentialPardonForm form("default");
			test.signForm(form);
			form.execute(test);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat test("test1", 1);
			std::cout << test;
			PresidentialPardonForm form("default");
			form.execute(test);
			test.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat test("test1", 1);
			std::cout << test;
			RobotomyRequestForm form("default");
			test.signForm(form);
			form.execute(test);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat test("test1", 1);
			std::cout << test;
			RobotomyRequestForm form("default");
			test.signForm(form);
			form.execute(test);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat test("test1", 1);
			std::cout << test;
			RobotomyRequestForm form("default");
			test.signForm(form);
			form.execute(test);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat test("test1", 1);
			std::cout << test;
			RobotomyRequestForm form("default");
			form.execute(test);
			test.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat test("test1", 1);
			std::cout << test;
			ShrubberyCreationForm form("default");
			test.signForm(form);
			form.execute(test);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	std::cout << std::endl;

	{
		try
		{
			Bureaucrat test("test1", 1);
			std::cout << test;
			ShrubberyCreationForm form("default");
			form.execute(test);
			test.signForm(form);
		}
		catch (std::exception &e)
		{
			std::cout << e.what() << std::endl;
		}
	}

	return (0);
}