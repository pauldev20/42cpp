/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:37:29 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/10 13:16:27 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include<iomanip>

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
	std::string	floatPseudoLiterals[] = {
		"+inff", "-inff", "nanf"
	};
	std::string	doublePseudoLiterals[] = {
		"-inf", "+inf", "nan"
	};
	std::string charVal = "";
	int			intVal = 0;
	float		floatVal = 0.0f;
	double		doubleVal = 0.0;

	for (int i = 0; i < 3; i++) {
		if (input == floatPseudoLiterals[i] || input == doublePseudoLiterals[i]) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		if (input == floatPseudoLiterals[i]) {
			floatVal = std::stof(input);
			std::cout << "float: " << floatVal << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(floatVal) << std::endl;
			return;
		}
		if (input == doublePseudoLiterals[i]) {
			doubleVal = std::stod(input);
			std::cout << "float: " << static_cast<float>(doubleVal) << "f" << std::endl;
			std::cout << "double: " << doubleVal << std::endl;
			return;
		}
	}

	if (input.size() == 1 && !std::isdigit(input[0]) && std::isprint(input[0])) {
		charVal = input[0];
		intVal = static_cast<int>(input[0]);
		floatVal = static_cast<float>(input[0]);
		doubleVal = static_cast<double>(input[0]);
	} else if (input.find_first_not_of("0123456789") == std::string::npos) {
		intVal = std::stoi(input);
		floatVal = static_cast<float>(intVal);
		doubleVal = static_cast<double>(intVal);
		if (std::isprint(intVal))
			charVal = std::string("'") + static_cast<char>(intVal) + std::string("'");
		else
			charVal = "Non displayable";
	} else if (input.find_first_not_of("0123456789.f-") == std::string::npos && input[input.size() - 1] == 'f') {
		floatVal = std::stof(input);
		intVal = static_cast<int>(floatVal);
		doubleVal = static_cast<double>(floatVal);
		if (std::isprint(intVal))
			charVal = std::string("'") + static_cast<char>(floatVal) + std::string("'");
		else
			charVal = "Non displayable";
	} else if (input.find_first_not_of("0123456789.-") == std::string::npos && input.find('.') != std::string::npos) {
		doubleVal = std::stod(input);
		intVal = static_cast<int>(doubleVal);
		floatVal = static_cast<float>(doubleVal);
		if (std::isprint(intVal))
			charVal = std::string("'") + static_cast<char>(doubleVal) + std::string("'");
		else
			charVal = "Non displayable";
	} else {
		std::cout << "Invalid Input" << std::endl;
		return;
	}

	std::cout << "char: " << charVal << std::endl;
	std::cout << "int: " << intVal << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << floatVal << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << doubleVal << std::endl;
}
