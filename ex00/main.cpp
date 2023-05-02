/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:56:52 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/27 02:24:12 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>	// std::cout, std::endl
#include <ctime>	// std::mktime
#include <sstream>	// std::istringstream
#include <cstdlib>	// std::strtof

std::tm	parseDate(std::string const &date)
{
	int	day, month, year = 0;
	std::istringstream is(date);
	char delimiter;

	if (date.find_first_not_of("0123456789-") != std::string::npos)
		throw std::exception();
	if (is >> year >> delimiter >> month >> delimiter >> day) {
		std::tm timeinfo;
		time_t rawtime = std::time(NULL);
		timeinfo = *localtime(&rawtime);
		timeinfo.tm_mday = day;
		timeinfo.tm_mon = month - 1;
		timeinfo.tm_year = year - 1900;
		std::mktime(&timeinfo);

		if (timeinfo.tm_year == year - 1900 && timeinfo.tm_mon == month - 1 && timeinfo.tm_mday == day)
			return (timeinfo);
		else
			throw std::exception();
	}
	throw std::exception();
}

float	parseValue(std::string const &date)
{
	float value = 0;

	if (date.find_first_not_of("0123456789.") != std::string::npos)
		throw std::exception();
	else if (date.find('.') && date.find('.') != date.find_last_of('.'))
		throw std::exception();
	value = std::strtof(date.c_str(), NULL);
	if (value < 1 || value > 999)
		throw std::exception();
	return (value);
}

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./btc <input.txt>" << std::endl;
		return (1);
	}
	std::cout << parseValue(argv[1]) << std::endl;
	// struct tm tm;
	// tm = parseDate(argv[1]);
	// std::cout << tm.tm_year + 1900 << " " << tm.tm_mon + 1 << " " << tm.tm_mday << std::endl;
	return (0);
}
