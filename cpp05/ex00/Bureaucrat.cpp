/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:47:40 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/24 15:24:16 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Bureaucrat::Bureaucrat(void) : _name("default"), _grade(150)
{
}

Bureaucrat::Bureaucrat(std::string const &name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
}

Bureaucrat::Bureaucrat(Bureaucrat const &src) : _name(src.getName()), _grade(src.getGrade())
{
}

Bureaucrat::~Bureaucrat(void)
{
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs.getGrade();
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             Getters And Setters                            */
/* -------------------------------------------------------------------------- */

std::string const	&Bureaucrat::getName(void) const
{
	return (this->_name);
}

int					Bureaucrat::getGrade(void) const
{
	return (this->_grade);
}

/* -------------------------------------------------------------------------- */
/*                             Operator Overloads                             */
/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &os, Bureaucrat const &rhs)
{
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function decrements the grade of a Bureaucrat object by one, throwing an exception if the
 * resulting grade is too high.
 */
void				Bureaucrat::incrementGrade(void)
{
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade--;
}

/**
 * The function decrements the grade of a bureaucrat by one, unless the resulting grade would be too
 * low.
 */
void				Bureaucrat::decrementGrade(void)
{
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade++;
}

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}
