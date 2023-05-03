/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:56:08 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/03 02:33:09 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>	// std::cout, std::endl

/* -------------------------------------------------------------------------- */
/*                                   Helpers                                  */
/* -------------------------------------------------------------------------- */

std::string	trimString(std::string const &input)
{
	if (input.empty()) return "";

	std::string::size_type first = input.find_first_not_of(" \t");
	std::string::size_type last = input.find_last_not_of(" \t");
	if (first == std::string::npos || last == std::string::npos) return "";

	return input.substr(first, last - first + 1);
}

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

void RPN::calculate(std::string const &input)
{
	std::string expression = trimString(input);

	if (expression.size() < 3)
		throw std::exception();
	if (input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		throw std::exception();

	for (std::string::iterator its = expression.begin(); its != expression.end(); its++) {
		if (*its == ' ')
			continue;
		if (std::isdigit(*its)) {
			operations.push(*its - '0');
			continue;
		}
		if (operations.size() < 2)
			throw std::exception();
		int64_t a = operations.top();
		operations.pop();
		int64_t b = operations.top();
		operations.pop();
		if (*its == '*') {
			operations.push(a * b);
		} else if (*its == '/') {
			if (a == 0)
				throw std::exception();
			operations.push(b / a);
		} else if (*its == '+') {
			operations.push(a + b);
		} else if (*its == '-') {
			operations.push(b - a);
		}
	}

	if (operations.size() != 1)
		throw std::exception();
	std::cout << operations.top() << std::endl;
}
