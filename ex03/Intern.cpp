/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:55:28 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 19:11:52 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Intern::Intern()
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern()
{
}

Intern	&Intern::operator=(Intern const &rhs)
{
	(void)rhs;
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

Form	*Intern::createRobotomyRequestForm(std::string const &target) const
{
	return (new RobotomyRequestForm(target));
}

Form	*Intern::createPresidentialPardonForm(std::string const &target) const
{
	return (new PresidentialPardonForm(target));
}

Form	*Intern::createShrubberyCreationForm(std::string const &target) const
{
	return (new ShrubberyCreationForm(target));
}

Form	*Intern::makeForm(std::string const &formName, std::string const &target) const
{
	std::string const forms[] = {"RobotomyRequest", "PresidentialPardon", "ShrubberyCreation"};
	Form *(Intern::*functions[])(std::string const &target) const = {&Intern::createRobotomyRequestForm, &Intern::createPresidentialPardonForm, &Intern::createShrubberyCreationForm};

	for (int i = 0; i < 3; i++)
	{
		if (formName == forms[i])
		{
			std::cout << "Intern creates " << formName << std::endl;
			return ((this->*functions[i])(target));
		}
	}
	std::cout << "Intern cannot create form " << formName << std::endl;
	return (NULL);
}
