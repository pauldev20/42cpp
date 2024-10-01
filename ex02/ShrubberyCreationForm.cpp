/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 15:43:33 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/24 16:00:33 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : Form("ShrubberyCreationForm", 145, 137), _target("default")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target) : Form("ShrubberyCreationForm", 145, 137), _target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) : Form(src), _target(src._target)
{
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs)
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

std::string const	ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * This function executes the ShrubberyCreationForm by creating a file with a shrubbery design and
 * printing a success message.
 * 
 * @param executor The `executor` parameter is a constant reference to a `Bureaucrat` object, which
 * represents the bureaucrat who is trying to execute the `ShrubberyCreationForm`.
 */
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (this->getSigned() == false)
		throw Form::FormNotSignedException();
	else if (executor.getGrade() > this->getGradeToExecute())
		throw Form::GradeTooLowException();
	else
	{
		std::ofstream	outFile((this->_target + "_shrubbery").c_str());

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

		std::cout << "Shrubbery successfully planted at " << this->_target << std::endl;
	}
}
