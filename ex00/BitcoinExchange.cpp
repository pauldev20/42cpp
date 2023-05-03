/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:29:30 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/03 01:49:24 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>	// std::cout, std::endl
#include <fstream>	// std::ifstream
#include <ctime>	// std::mktime
#include <sstream>	// std::istringstream
#include <cstdlib>	// std::strtof
#include <algorithm>// std::count
#include <iomanip>	// std::setfill, std::setw

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
		std::tm tm;

		tm.tm_year = year - 1900;
		tm.tm_mon = month - 1;
		tm.tm_mday = day;
		tm.tm_hour = 0;
    	tm.tm_min = 0;
		tm.tm_sec = 0;
		tm.tm_isdst = 0;
		tm.tm_gmtoff = 0;
		tm.tm_zone = NULL;
		time_t	timestamp = std::mktime(&tm);

		if (tm.tm_year == year - 1900 && tm.tm_mon == month - 1 && tm.tm_mday == day) {
			return (timestamp);
		} else
			throw BitcoinExchange::InvalidDateException();
	}
	throw BitcoinExchange::InvalidDateException();
}

float	parseInputValue(std::string const &input)
{
	float value = 0;
	std::ostringstream tmp;

	if (input.find_first_not_of("-0123456789.") != std::string::npos)
		throw BitcoinExchange::InvalidValueException();
	else if (input.find('.') && input.find('.') != input.find_last_of('.'))
		throw BitcoinExchange::InvalidValueException();
	if (input.find('.') != std::string::npos)
		return(std::strtof(input.c_str(), NULL));
	std::istringstream(input) >> value;
	if (value < 0)
		throw BitcoinExchange::InvalidValueNotPositiveException();
	else if (value > 1000)
		throw BitcoinExchange::InvalidValueTooLargeException();
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
			try {
				time_t	inputTime = parseDate(date);
				if (inputTime < 1231718400) {
					std::cout << "Error: date is too early." << std::endl;
					continue;
				}
				std::map<time_t, float>::iterator	index = this->data.upper_bound(inputTime);
				if (index == this->data.begin())
					index = this->data.end();
				else
					index--;
				std::tm	*timeinfo = std::localtime(&inputTime);
				float	parsedValue = parseInputValue(value);
				std::cout << std::setfill('0');
				std::cout << timeinfo->tm_year + 1900 << "-" << std::setw(2) << timeinfo->tm_mon + 1 << "-" << std::setw(2) << timeinfo->tm_mday << " => ";
				std::cout << parsedValue << " = ";
				std::cout << parsedValue * (*index).second << std::endl;
			} catch (const BitcoinExchange::InvalidValueNotPositiveException &e) {
				std::cout << "Error: not a positive number." << std::endl;
			} catch (const BitcoinExchange::InvalidValueTooLargeException &e) {
				std::cout << "Error: too large a number." << std::endl;
			} catch (const BitcoinExchange::InvalidDateException &e) {
				std::cout << "Error: bad input => " << date << std::endl;
			} catch (const std::exception &e) {
				std::cout << "Error: " << e.what() << std::endl;
			}
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

char const	*BitcoinExchange::InvalidValueNotPositiveException::what() const throw() {
	return ("Invalid value: value must be positive");
}

char const	*BitcoinExchange::InvalidValueTooLargeException::what() const throw() {
	return ("Invalid value: value must be less than 1000");
}
