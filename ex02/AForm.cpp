/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:04:40 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/24 15:49:46 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Form::Form(void) : _name("default"), _signed(false), _grade_to_sign(150), _grade_to_execute(150)
{
}

Form::Form(std::string const &name, int grade_to_sign, int grade_to_execute) : _name(name), _signed(false), _grade_to_sign(grade_to_sign), _grade_to_execute(grade_to_execute)
{
	if (grade_to_sign < 1 || grade_to_execute < 1)
		throw Form::GradeTooHighException();
	else if (grade_to_sign > 150 || grade_to_execute > 150)
		throw Form::GradeTooLowException();
}

Form::Form(Form const &src) : _name(src.getName()), _signed(src.getSigned()), _grade_to_sign(src.getGradeToSign()), _grade_to_execute(src.getGradeToExecute())
{
}

Form::~Form(void)
{
}

Form	&Form::operator=(Form const &rhs)
{
	if (this != &rhs)
		this->_signed = rhs.getSigned();
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             Getters And Setters                            */
/* -------------------------------------------------------------------------- */

std::string const	&Form::getName(void) const
{
	return (this->_name);
}

bool				Form::getSigned(void) const
{
	return (this->_signed);
}

int					Form::getGradeToSign(void) const
{
	return (this->_grade_to_sign);
}

int					Form::getGradeToExecute(void) const
{
	return (this->_grade_to_execute);
}

/* -------------------------------------------------------------------------- */
/*                             Operator Overloads                             */
/* -------------------------------------------------------------------------- */

std::ostream &operator<<(std::ostream &os, Form const &rhs)
{
	os << "Form " << rhs.getName() 
		<< " is " << (rhs.getSigned() ? "signed" : "not signed") 
		<< " and requires a grade of " << rhs.getGradeToSign() 
		<< " to sign and a grade of " << rhs.getGradeToExecute()
		<< " to execute";
	return os;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * This function allows a bureaucrat to sign a form if their grade is high enough.
 * 
 * @param bureaucrat The parameter `bureaucrat` is a constant reference to an object of the class
 * `Bureaucrat`. It is used to check if the bureaucrat has a high enough grade to sign the form.
 */
void				Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_grade_to_sign)
		throw Form::GradeTooLowException();
	else
		this->_signed = true;
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

const char *Form::FormNotSignedException::what() const throw()
{
	return ("Form Not Signed");
}
