/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:37:29 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/10 00:13:11 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

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

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

void				ScalarConverter::convert(std::string const input)
{
	std::string	pseudoLiterals[] = {
		"+inff", "-inff",
		"-inf", "+inf",
		"nanf", "nan"
	};
	std::string charVal = "";
	int			intVal = 0;
	float		floatVal = 0.0f;
	double		doubleVal = 0.0;

	if (input.size() == 1 && !std::isdigit(input[0]) && std::isprint(input[0])) {
		charVal = std::string("'") + input[0] + std::string("'");
		std::cout << "char: " << charVal << std::endl;
		std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
		std::cout << "float: " << static_cast<float>(input[0]) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(input[0]) << ".0" << std::endl;
		return;
	} else if (input.find_first_not_of("0123456789") == std::string::npos) {
		intVal = std::stoi(input);
		if (std::isprint(intVal))
			charVal = std::string("'") + static_cast<char>(intVal) + std::string("'");
		else
			charVal = "Non displayable";
		std::cout << "char: " << charVal << std::endl;
		std::cout << "int: " << intVal << std::endl;
		std::cout << "float: " << static_cast<float>(intVal) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(intVal) << ".0" << std::endl;
		return;
	} else if (input[input.size() - 1] == 'f') {
		floatVal = std::stof(input);
		intVal = std::stoi(input);
		if (std::isprint(intVal))
			charVal = std::string("'") + static_cast<char>(intVal) + std::string("'");
		else
			charVal = "Non displayable";
		std::cout << "char: " << charVal << std::endl;
		std::cout << "int: " << intVal << std::endl;
		std::cout << "float: " << floatVal << "f" << std::endl;
		std::cout << "double: " << static_cast<double>(floatVal) << std::endl;
		return;
	} else if (input.find_first_not_of("0123456789.") == std::string::npos && input.find('.') != std::string::npos) {
		doubleVal = std::stod(input);
		intVal = std::stoi(input);
		if (std::isprint(intVal))
			charVal = std::string("'") + static_cast<char>(intVal) + std::string("'");
		else
			charVal = "Non displayable";
		std::cout << "char: " << charVal << std::endl;
		std::cout << "int: " << intVal << std::endl;
		std::cout << "float: " << static_cast<float>(doubleVal) << "f" << std::endl;
		std::cout << "double: " << doubleVal << std::endl;
		return;
	} else {
		for (int i = 0; i < 6; i++) {
			if (input == pseudoLiterals[i]) {
				std::cout << "char: " << pseudoLiterals[i] << std::endl;
				std::cout << "int: " << pseudoLiterals[i] << std::endl;
				std::cout << "float: " << pseudoLiterals[i] << std::endl;
				std::cout << "double: " << pseudoLiterals[i] << std::endl;
				return;
			}
		}
		std::cout << "Invalid input" << std::endl;
	}
}
