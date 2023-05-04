/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 18:29:30 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/04 02:00:52 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <algorithm>	// std::count
#include <iostream>		// std::cout, std::endl
#include <fstream>		// std::ifstream
#include <sstream>		// std::istringstream
#include <cstdlib>		// std::strtof
#include <iomanip>		// std::setfill, std::setw
#include <ctime>		// std::mktime

/* -------------------------------------------------------------------------- */
/*                                   Helpers                                  */
/* -------------------------------------------------------------------------- */

/**
 * The function parses a string representing a date and returns a time_t timestamp.
 * 
 * @param date The input date string in the format "YYYY-MM-DD".
 * 
 * @return The function `parseDate` returns a `time_t` value representing the timestamp of the input
 * date string.
 */
time_t	parseDate(std::string const &date)
{
	int	day = 0, month = 0, year = 0;
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

/**
 * The function parses and validates a string input as a float value within certain constraints, and
 * throws exceptions if the input is invalid.
 * 
 * @param input The input string that needs to be parsed and converted to a float value.
 * 
 * @return a float value.
 */
float	parseInputValue(std::string const &input)
{
	float value = 0;
	std::ostringstream tmp;

	if (input.find_first_not_of("-0123456789.") != std::string::npos)
		throw BitcoinExchange::InvalidValueException();
	else if (input.find('.') && input.find('.') != input.find_last_of('.'))
		throw BitcoinExchange::InvalidValueException();
	else if (input.find('.') == 0 || input.find('.') == input.size() - 1)
		throw BitcoinExchange::InvalidValueException();
	if (input.find('.') != std::string::npos)
		return(std::strtof(input.c_str(), NULL));
	std::istringstream(input) >> value;
	tmp << value;
	if (tmp.str() != input)
		throw BitcoinExchange::InvalidValueException();
	if (value < 0)
		throw BitcoinExchange::InvalidValueNotPositiveException();
	else if (value > 1000)
		throw BitcoinExchange::InvalidValueTooLargeException();
	return (value);
}

/**
 * The function parses a string input and returns a float value, throwing an exception if the input is
 * invalid.
 * 
 * @param input The input parameter is a constant reference to a string that contains the _data value to
 * be parsed as a float.
 * 
 * @return a float value.
 */
float	parseDataValue(std::string const &input) {
	if (input.find_first_not_of("0123456789.") != std::string::npos)
		throw BitcoinExchange::InvalidValueException();
	else if (input.find('.') && input.find('.') != input.find_last_of('.'))
		throw BitcoinExchange::InvalidValueException();
	else if (input.find('.') == 0 || input.find('.') == input.size() - 1)
		throw BitcoinExchange::InvalidValueException();
	return (std::strtof(input.c_str(), NULL));
}

/**
 * The function finds the exact or lower timestamp in a map and returns an iterator to the
 * corresponding key-value pair.
 * 
 * @param map A reference to a std::map container that stores key-value pairs of type time_t and float.
 * @param timestamp The timestamp parameter is a variable of type time_t, which represents a point in
 * time as the number of seconds since January 1, 1970, 00:00:00 UTC. It is used as a key in the
 * std::map container to find the corresponding value.
 * 
 * @return an iterator to the element in the given `std::map` that has a key equal to the given
 * `timestamp`, or the element with the greatest key less than the given `timestamp` if there is no
 * element with a key equal to the given `timestamp`. If the given `timestamp` is less than the
 * smallest key in the map, the function returns an iterator to the end of the map.
 */
std::map<time_t, float>::iterator findExactOrLower(std::map<time_t, float> &map, time_t const &timestamp) {
	std::map<time_t, float>::iterator	index = map.lower_bound(timestamp);
	if ((*index).first != timestamp) {	
		if (index == map.begin())
			index = map.end();
		else
			index--;
	}
	return (index);
}

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function reads _data from a database file and stores it in a map.
 * 
 * @param database A string representing the file path of the database file to be opened and read.
 */
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
			this->_data.insert(std::pair<time_t, float>(parseDate(date), parseDataValue(value)));
		}
		lineCount++;
	}
	if (lineCount < 2)
		throw BitcoinExchange::InvalidDatabaseException();
	inFile.close();
}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src) {
	*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(BitcoinExchange const &rhs) {
	if (this != &rhs) {
		this->_data = rhs._data;
	}
	return (*this);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * The function reads and parses an input file, executing queries based on the contents of each line.
 * 
 * @param path A string representing the file path of the input file to be parsed.
 */
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
				this->executeQuery(date, value);
			} catch (const BitcoinExchange::DateTooEarlyException &e) {
				std::cout << "Error: date is too early." << std::endl;
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

/**
 * The function executes a query by parsing input date and value, checking if the date is not too
 * early, finding the corresponding value in a map, and outputting the result of multiplying the parsed
 * value with the found value.
 * 
 * @param date The date parameter is a string representing a date in the format "YYYY-MM-DD".
 * @param value The value parameter is a string representing the value of Bitcoin at a specific date.
 */
void	BitcoinExchange::executeQuery(std::string const &date, std::string const &value)
{
	time_t	inputTime = parseDate(date);
	float	parsedValue = parseInputValue(value);
	if (inputTime < 1231718400)
		throw BitcoinExchange::DateTooEarlyException();

	std::map<time_t, float>::iterator	index = findExactOrLower(this->_data, inputTime);

	std::tm	*timeinfo = std::localtime(&inputTime);
	std::cout << std::setfill('0');
	std::cout << timeinfo->tm_year + 1900 << "-" << std::setw(2) << timeinfo->tm_mon + 1 << "-" << std::setw(2) << timeinfo->tm_mday << " => ";
	std::cout << parsedValue << " = ";
	std::cout << parsedValue * (*index).second << std::endl;
}


/* -------------------------------------------------------------------------- */
/*                                 Exceptions                                 */
/* -------------------------------------------------------------------------- */

char const	*BitcoinExchange::InvalidDatabaseException::what() const throw() {
	return ("Invalid database file or file path");
}

char const	*BitcoinExchange::InvalidValueException::what() const throw() {
	return ("Invalid value");
}

char const	*BitcoinExchange::InvalidDateException::what() const throw() {
	return ("Invalid date");
}

char const	*BitcoinExchange::InvalidInputFileException::what() const throw() {
	return ("Invalid input file or file path");
}

char const	*BitcoinExchange::InvalidValueNotPositiveException::what() const throw() {
	return ("Invalid value: value must be positive");
}

char const	*BitcoinExchange::InvalidValueTooLargeException::what() const throw() {
	return ("Invalid value: value must be less than 1000");
}

char const	*BitcoinExchange::DateTooEarlyException::what() const throw() {
	return ("Date to early");
}
