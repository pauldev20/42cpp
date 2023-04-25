/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:37:29 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/25 15:45:40 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>	// std::cout, std::endl
#include <iomanip>	// std::setprecision
#include <cstdlib>	// std::strtof, std::strtod
#include <sstream>	// std::stringstream
#include <limits>	// std::numeric_limits

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
/*                               Private Methods                              */
/* -------------------------------------------------------------------------- */

/**
 * The function handles pseudo-literals and converts them to float and double values.
 * 
 * @param input The input string that needs to be converted.
 * 
 * @return a boolean value.
 */
bool			ScalarConverter::handlePseudo(std::string const &input)
{
	float		floatVal = 0.0f;
	double		doubleVal = 0.0;
	std::string	floatPseudoLiterals[] = {
		"+inff", "-inff", "nanf"
	};
	std::string	doublePseudoLiterals[] = {
		"-inf", "+inf", "nan"
	};

	for (int i = 0; i < 3; i++) {
		if (input == floatPseudoLiterals[i] || input == doublePseudoLiterals[i]) {
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
		}
		if (input == floatPseudoLiterals[i]) {
			floatVal = std::strtof(input.c_str(), NULL);
			std::cout << "float: " << floatVal << "f" << std::endl;
			std::cout << "double: " << static_cast<double>(floatVal) << std::endl;
			return (true);
		}
		if (input == doublePseudoLiterals[i]) {
			doubleVal = std::strtod(input.c_str(), NULL);
			std::cout << "float: " << static_cast<float>(doubleVal) << "f" << std::endl;
			std::cout << "double: " << doubleVal << std::endl;
			return (true);
		}
	}
	return (false);
}

/**
 * The function prints the output of a scalar conversion, including the converted char, int, float, and
 * double values.
 * 
 * @param input The input string that was converted to the other data types (char, int, float, double).
 * @param charVal The string representation of the converted char value.
 * @param intVal intVal is an integer value that represents the converted input value. It is used to
 * determine the char output and the int output.
 * @param floatVal floatVal is a float variable that stores the converted value of the input string to
 * a float data type. It is used in the printOutput function to print the float value in the output.
 * @param doubleVal doubleVal is a double precision floating point number that represents the converted
 * input value. It is one of the parameters passed to the printOutput function in the ScalarConverter
 * class. The function uses this parameter to print the converted value in double format.
 */
void			ScalarConverter::printOutput(std::string input, std::string const &charVal, int const &intVal, float const &floatVal, double const &doubleVal)
{
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

	if (input.find(".") != std::string::npos) {
		if (input.find("f") != std::string::npos)
			input.erase(input.length() - 1);
		std::cout << std::setprecision(input.substr(input.find(".") + 1).length());
	} else
		std::cout << std::setprecision(1);
	std::cout << "float: " << std::fixed << floatVal << "f" << std::endl;
	std::cout << "double: " << std::fixed << doubleVal << std::endl;
}

/**
 * The function checks if the input string is valid for conversion to a scalar value.
 * 
 * @param input The input string that needs to be checked for validity in the ScalarConverter class.
 */
void			ScalarConverter::handleInputError(std::string const &input)
{
	// check if only allowed characters are present
	if (input.find_first_not_of("0123456789.f-+") != std::string::npos)
		throw ScalarConverter::InvalidInputException();

	// check if the signs are correct
	else if (input.find('-') != input.find_last_of('-') || input.find('+') != input.find_last_of('+'))
		throw ScalarConverter::InvalidInputException();
	else if (input.find('-') != std::string::npos && input.find('+') != std::string::npos)
		throw ScalarConverter::InvalidInputException();
	else if (input.find('-') != std::string::npos && input.find('-') != 0)
		throw ScalarConverter::InvalidInputException();
	else if (input.find('+') != std::string::npos && input.find('+') != 0)
		throw ScalarConverter::InvalidInputException();

	// check if there are multiple dots or f's
	else if (input.find('f') != std::string::npos && input.find('f') != input.find_last_of('f'))
		throw ScalarConverter::InvalidInputException();
	else if (input.find('.') != std::string::npos && input.find('.') != input.find_last_of('.'))
		throw ScalarConverter::InvalidInputException();
	
	// check if there are dots or f's in the wrong places
	else if (input.find('.') != std::string::npos && input.find('.') != 0 && !std::isdigit(input[input.find('.') - 1]))
		throw ScalarConverter::InvalidInputException();
	else if (input.find('f') != std::string::npos && input.find('f') != 0 && !std::isdigit(input[input.find('f') - 1]))
		throw ScalarConverter::InvalidInputException();
	
	// check that there is a dot if a f is present
	else if (input.find('f') != std::string::npos && input.find('.') == std::string::npos)
		throw ScalarConverter::InvalidInputException();
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function converts a given input string into a character, integer, float, and double value and
 * prints the output.
 * 
 * @param input The input string that needs to be converted to different scalar types.
 * 
 * @return The function does not have a return type specified, so it is likely returning `void`.
 */
void				ScalarConverter::convert(std::string const &input)
{
	std::string charVal = "";
	int			intVal = 0;
	float		floatVal = 0.0f;
	double		doubleVal = 0.0;

	if (ScalarConverter::handlePseudo(input))
		return;

	ScalarConverter::handleInputError(input);

	if (input.size() == 1 && !std::isdigit(input[0]) && std::isprint(input[0])) {
		charVal = input[0];
		intVal = static_cast<int>(input[0]);
		floatVal = static_cast<float>(input[0]);
		doubleVal = static_cast<double>(input[0]);
	} else if (input.find_first_not_of("0123456789-+") == std::string::npos) {
		std::ostringstream tmp;
		intVal = std::atoi(input.c_str());
    	tmp << intVal;
		if (tmp.str() != (input.c_str() + (input.find('+') != std::string::npos ? 1 : 0)))
			throw ScalarConverter::OverflowException();
		floatVal = static_cast<float>(intVal);
		doubleVal = static_cast<double>(intVal);
		charVal = static_cast<char>(intVal);
	} else if (input.find('f') != std::string::npos) {
		floatVal = std::strtof(input.c_str(), NULL);
		intVal = static_cast<int>(floatVal);
		doubleVal = static_cast<double>(floatVal);
		charVal = static_cast<char>(floatVal);
	} else {
		doubleVal = std::strtod(input.c_str(), NULL);
		intVal = static_cast<int>(doubleVal);
		floatVal = static_cast<float>(doubleVal);
		charVal = static_cast<char>(doubleVal);
	}

	ScalarConverter::printOutput(input, charVal, intVal, floatVal, doubleVal);
}

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char *ScalarConverter::InvalidInputException::what() const throw()
{
	return ("Invalid Input");
}

const char *ScalarConverter::OverflowException::what() const throw()
{
	return ("Overflow");
}
