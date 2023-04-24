/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:55:28 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/24 16:45:26 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Intern::Intern(void)
{
}

Intern::Intern(Intern const &src)
{
	*this = src;
}

Intern::~Intern(void)
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

/**
 * The function "makeForm" in the "Intern" class creates a form based on the given form name and
 * target, using an array of form names and an array of functions to create the appropriate form.
 * 
 * @param formName A string representing the name of the form that needs to be created.
 * @param target The "target" parameter is a string that represents the target of the form, which could
 * be a person, a place, or an object depending on the type of form being created. It is used as an
 * argument in the functions that create the specific forms.
 * 
 * @return The function `makeForm` returns a pointer to a `Form` object. If the `formName` parameter
 * matches one of the three strings in the `forms` array, the corresponding function pointer in the
 * `functions` array is called to create and return a new instance of the corresponding `Form`
 * subclass. If `formName` does not match any of the strings in `forms`, the
 */
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
