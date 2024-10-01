/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 18:52:50 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/24 16:40:34 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class Intern
{
	private:
		Form	*createRobotomyRequestForm(std::string const &target) const;
		Form	*createPresidentialPardonForm(std::string const &target) const;
		Form	*createShrubberyCreationForm(std::string const &target) const;

	public:
		Intern(void);
		Intern(Intern const &src);
		~Intern(void);
		Intern	&operator=(Intern const &rhs);

		Form	*makeForm(std::string const &formName, std::string const &target) const;
};

#endif
