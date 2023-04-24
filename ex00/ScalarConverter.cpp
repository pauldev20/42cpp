/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:37:29 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/25 01:29:34 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iomanip>
#include <cstdlib>
#include <sstream>
#include <limits>

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
			floatVal = std::strtof(input.c_str(), NULL);
			std::cout << "float: " << floatVal << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(floatVal) << std::endl;
			return;
		}
		if (input == doublePseudoLiterals[i]) {
			doubleVal = std::strtod(input.c_str(), NULL);
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
	} else if (input.find_first_not_of("0123456789-+") == std::string::npos) {
		std::ostringstream tmp;
		intVal = std::atoi(input.c_str());
    	tmp << intVal;
		if (tmp.str() != input) {
			std::cout << "Overflow!" << std::endl;
			return;
		}
		floatVal = static_cast<float>(intVal);
		doubleVal = static_cast<double>(intVal);
		charVal = static_cast<char>(intVal);
	} else if (input.find_first_not_of("0123456789.f-+") == std::string::npos
		&& input.find('.') == input.find_last_of('.') && input.find('.') != 0 && input.find('.') != std::string::npos) {
		if (std::isdigit(input[input.size() - 2]) && input[input.size() - 1] == 'f') {
			floatVal = std::strtof(input.c_str(), NULL);
			intVal = static_cast<int>(floatVal);
			doubleVal = static_cast<double>(floatVal);
			charVal = static_cast<char>(floatVal);
		}
		else if (std::isdigit(input[input.size() - 1])) {
			doubleVal = std::strtod(input.c_str(), NULL);
			intVal = static_cast<int>(doubleVal);
			floatVal = static_cast<float>(doubleVal);
			charVal = static_cast<char>(doubleVal);
		} else
			goto invalid_in;
	} else {
		invalid_in:
		std::cout << "Invalid Input" << std::endl;
		return;
	}

	if ((unsigned)intVal - ' ' < 95)
		std::cout << "char: '" << charVal << "'" << std::endl;
	else if (intVal < 0 || intVal > 127)
		std::cout << "char: impossible" << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;
	if ((doubleVal > std::numeric_limits<int>::max() || doubleVal < std::numeric_limits<int>::min())
		|| (floatVal > std::numeric_limits<int>::max() || floatVal < std::numeric_limits<int>::min()))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intVal << std::endl;
	std::cout << "float: " << floatVal << "f" << std::endl; //<< std::fixed << std::setprecision(1) 
	std::cout << "double: " << doubleVal << std::endl;
}
