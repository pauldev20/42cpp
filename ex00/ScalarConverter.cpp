/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:37:29 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 21:55:37 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(ScalarConverter const &src)
{
	*this = src;
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter		&ScalarConverter::operator=(ScalarConverter const &rhs)
{
	(void)rhs;
	return (*this);
}

void				ScalarConverter::convert(std::string const input)
{
	// std::cout << "test: " << std::stoi(input) << std::endl;
	std::cout << "char: ";
	try
	{
		char c = static_cast<char>(std::stoi(input));
		if (std::isprint(c))
			std::cout << "'" << c << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "int: ";
	try
	{
		int i = std::stoi(input);
		std::cout << i << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "float: ";
	try
	{
		float f = std::stof(input);
		std::cout << f << "f" << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}

	std::cout << "double: ";
	try
	{
		double d = std::stod(input);
		std::cout << d << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}