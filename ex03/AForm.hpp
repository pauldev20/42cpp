/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:58:50 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 19:14:39 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		std::string const	_name;
		bool				_signed;
		int const			_grade_to_sign;
		int const			_grade_to_execute;

	public:
		Form();
		Form(std::string const &name, int grade_to_sign, int grade_to_execute);
		Form(Form const &src);
		virtual ~Form();
		Form	&operator=(Form const &rhs);

		std::string const	&getName() const;
		bool				getSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;

		void				beSigned(Bureaucrat const &bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const =0;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class FormNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream	&operator<<(std::ostream &os, Form const &rhs);

#endif
