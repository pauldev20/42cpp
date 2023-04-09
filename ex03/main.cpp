/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 17:09:22 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 19:19:01 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Intern.hpp"

int main(void)
{
	Intern  someRandomIntern;
	Form*   rrf;

	rrf = someRandomIntern.makeForm("RobotomyRequest", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	rrf = someRandomIntern.makeForm("???", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	rrf = someRandomIntern.makeForm("PresidentialPardon", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	rrf = someRandomIntern.makeForm("ShrubberyCreation", "Bender");
	if (rrf)
	{
		std::cout << *rrf << std::endl;
		delete rrf;
	}

	return (0);
}