/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:43:33 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 18:48:08 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
{
	if (this != &rhs)
	{
		Form::operator=(rhs);
		this->_target = rhs._target;
	}
	return *this;
}

/* -------------------------------------------------------------------------- */
/*                             Getters And Setters                            */
/* -------------------------------------------------------------------------- */

std::string const	ShrubberyCreationForm::getTarget() const
{
	return _target;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	else
	{
		std::ofstream	outFile(this->_target + "_shrubbery");

		for (int i = 0; i < 3; i++)
		{
			outFile << "    ###		" << std::endl;
			outFile << "   #o###	" << std::endl;
			outFile << " #####o###	" << std::endl;
			outFile << "#o#\\#|#/###	" << std::endl;
			outFile << " ###\\|/#o#	" << std::endl;
			outFile << "  # }|{  #	" << std::endl;
			outFile << "    }|{		" << std::endl << std::endl;
		}
		outFile.close();
	}
}
