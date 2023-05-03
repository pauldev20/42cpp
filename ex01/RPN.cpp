/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:56:08 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/04 01:24:48 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>	// std::cout, std::endl

/* -------------------------------------------------------------------------- */
/*                           Statics Initializiation                          */
/* -------------------------------------------------------------------------- */

std::stack<int64_t> RPN::operations;

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

RPN::~RPN(void) {}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function calculates the result of a Reverse Polish Notation expression.
 * 
 * @param expression The input expression in Reverse Polish Notation (RPN) format that needs to be
 * evaluated.
 */
int64_t RPN::calculate(std::string const &expression)
{
	if (expression.size() < 3)
		throw RPN::TooShortInputException();
	if (expression.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw RPN::InvalidCharacterException();

	for (std::string::const_iterator its = expression.begin(); its != expression.end(); its++) {
		if (*its == ' ')
			continue;
		if (std::isdigit(*its)) {
			operations.push(*its - '0');
			continue;
		}
		if (operations.size() < 2)
			throw RPN::InvalidInputException();
		int64_t a = operations.top();
		operations.pop();
		int64_t b = operations.top();
		operations.pop();
		if (*its == '*') {
			operations.push(a * b);
		} else if (*its == '/') {
			if (a == 0)
				throw RPN::DivisionByZeroException();
			operations.push(b / a);
		} else if (*its == '+') {
			operations.push(a + b);
		} else if (*its == '-') {
			operations.push(b - a);
		}
	}

	if (operations.size() != 1)
		throw RPN::InvalidInputException();
	return (operations.top());
}

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

const char *RPN::InvalidCharacterException::what() const throw()
{
	return ("Invalid character found");
}

const char *RPN::TooShortInputException::what() const throw()
{
	return ("The input is too short");
}

const char *RPN::InvalidInputException::what() const throw()
{
	return ("Invalid input");
}

const char *RPN::DivisionByZeroException::what() const throw()
{
	return ("Division by zero");
}
