/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:04:40 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 19:15:33 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Form::Form() : _name("default"), _signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
}

Form::Form(std::string const &name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150)
		throw Form::GradeTooLowException();
	if (grade_to_execute < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src.getName()), _signed(src.getSigned()), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute())
{
}

Form::~Form()
{
}

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
	{
		this->_signed = rhs.getSigned();
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                             Getters And Setters                            */
/* -------------------------------------------------------------------------- */

std::string const	&Form::getName() const
{
	return _name;
}

bool				Form::getSigned() const
{
	return _signed;
}

int					Form::getGradeToSign() const
{
	return _grade_to_sign;
}

int					Form::getGradeToExecute() const
{
	return _grade_to_execute;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
}

/* -------------------------------------------------------------------------- */
/*                             Operator Overloads                             */
/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &os, Form const &rhs)
{
	os << "Form " << rhs.getName() 
		<< " is " << (rhs.getSigned() ? "signed" : "not signed") 
		<< " and requires a grade of " << rhs.getGradeToSign() 
		<< " to sign and a grade of " << rhs.getGradeToExecute() << " to execute";
	return os;
}

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char *Form::GradeTooHighException::what() const throw()
{
	return ("Grade Too High");
}

const char *Form::GradeTooLowException::what() const throw()
{
	return ("Grade Too Low");
}
