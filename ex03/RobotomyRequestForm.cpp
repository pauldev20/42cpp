/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:02:29 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 16:08:21 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72, 45), _target("default")
{
}

RobotomyRequestForm::RobotomyRequestForm(std::string const &target) : Form("RobotomyRequestForm", 72, 45), _target(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) : Form(src), _target(src._target)
{
}

RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
		this->_target = rhs._target;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                             Getters And Setters                            */
/* -------------------------------------------------------------------------- */

std::string const	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

void				RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	static int	fail = 0;

	if (this->getSigned() == false)
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();\
	std::cout << "BZZZZZZ" << std::endl;
	if (fail++ % 2)
		std::cout << this->_target << " has been robotomized successfully" << std::endl;\
	else
		std::cout << this->_target << " has not been robotomized successfully" << std::endl;
}
