/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:29:30 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/02 19:29:19 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>
#include <ctime>	// std::mktime
#include <sstream>	// std::istringstream
#include <cstdlib>	// std::strtof

/* -------------------------------------------------------------------------- */
/*                                   Helpers                                  */
/* -------------------------------------------------------------------------- */

time_t	parseDate(std::string const &date)
{
	int	day, month, year = 0;
	std::istringstream is(date);
	char delimiter;

	if (date.find_first_not_of("0123456789-") != std::string::npos)
		throw BitcoinExchange::InvalidDateException();
	else if (std::count(date.begin(), date.end(), '-') != 2)
		throw BitcoinExchange::InvalidDateException();
	if (is >> year >> delimiter >> month >> delimiter >> day) {
		std::tm timeinfo;

		time_t rawtime = std::time(NULL);
		timeinfo = *localtime(&rawtime);
		timeinfo.tm_mday = day;
		timeinfo.tm_mon = month - 1;
		timeinfo.tm_year = year - 1900;
		time_t	timestamp = std::mktime(&timeinfo);

		if (timeinfo.tm_year == year - 1900 && timeinfo.tm_mon == month - 1 && timeinfo.tm_mday == day)
			return (timestamp * 1000);
		else
			throw BitcoinExchange::InvalidDateException();
	}
	throw BitcoinExchange::InvalidDateException();
}

float	parseInputValue(std::string const &input)
{
	float value = 0;
	std::ostringstream tmp;

	if (input.find_first_not_of("0123456789.") != std::string::npos)
		throw BitcoinExchange::InvalidValueException();
	else if (input.find('.') && input.find('.') != input.find_last_of('.'))
		throw BitcoinExchange::InvalidValueException();
	if (input.find('.') != std::string::npos)
		return(std::strtof(input.c_str(), NULL));
	std::istringstream(input) >> value;
	if (value < 1 || value > 999)
		throw BitcoinExchange::InvalidValueException();
	return (value);
}

float	parseDataValue(std::string const &input) {
	if (input.find_first_not_of("0123456789.") != std::string::npos)
		throw BitcoinExchange::InvalidValueException();
	else if (input.find('.') && input.find('.') != input.find_last_of('.'))
		throw BitcoinExchange::InvalidValueException();
	return (std::strtof(input.c_str(), NULL));
}

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

BitcoinExchange::BitcoinExchange(std::string const &database) {
	std::ifstream inFile(database.c_str());

	if (!inFile.good() || !inFile.is_open())
		throw BitcoinExchange::InvalidDatabaseException();
	int	lineCount = 0;
	for (std::string line; std::getline(inFile, line);) {
		std::string date = line.substr(0, line.find_first_of(','));
		std::string value = line.substr(line.find_first_of(',') + 1);
		if (lineCount == 0 && (date != "date" || value != "exchange_rate"))
			throw BitcoinExchange::InvalidDatabaseException();
		else if (lineCount != 0) {
			this->data.insert(std::pair<time_t, float>(parseDate(date), parseDataValue(value)));
		}
		lineCount++;
	}
	inFile.close();
	// for(std::map<time_t, float>::iterator it = this->data.begin(); it != this->data.end(); ++it) {
	// 	std::cout << it->first << " " << it->second << std::endl;
	// }
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs) {
		this->data = rhs.data;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

void	BitcoinExchange::parseInputFile(std::string const &path) {
	std::ifstream inFile(path.c_str());

	if (!inFile.good() || !inFile.is_open())
		throw BitcoinExchange::InvalidInputFileException();
	int	lineCount = 0;
	for (std::string line; std::getline(inFile, line);) {
		std::string date = line.substr(0, line.find(" | "));
		std::string value = line.substr(line.find(" | ") + 3);
		if (lineCount == 0 && (date != "date" || value != "value"))
			throw BitcoinExchange::InvalidInputFileException();
		else if (lineCount != 0) {
			std::cout << parseDate(date) * 1000 << " " << parseInputValue(value) << std::endl;
		}
		lineCount++;
	}
	inFile.close();
}

/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

char const	*BitcoinExchange::InvalidDatabaseException::what() const throw() {
	return ("Invalid database file or file path");
}

char const	*BitcoinExchange::InvalidInputFileException::what() const throw() {
	return ("Invalid input file or file path");
}

char const	*BitcoinExchange::InvalidDateException::what() const throw() {
	return ("Invalid date");
}

char const	*BitcoinExchange::InvalidValueException::what() const throw() {
	return ("Invalid value");
}
