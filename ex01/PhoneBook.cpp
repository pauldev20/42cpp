/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 18:05:37 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/13 16:28:54 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

#include <sstream>
#include <iomanip>

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

PhoneBook::PhoneBook(void)
{
	this->_contactCount = 0;
}

PhoneBook::~PhoneBook(void)
{
}

/* -------------------------------------------------------------------------- */
/*                               Private Methods                              */
/* -------------------------------------------------------------------------- */

/**
 * It reads a line from the standard input and returns it
 * 
 * @param str The string to be displayed to the user.
 * 
 * @return A string.
 */
std::string	PhoneBook::_readInput(std::string str)
{
	std::string	line;
	bool		valid = false;

	while (!valid)
	{
		std::cout << str << ": ";
		std::getline(std::cin, line);
		if (!std::cin || std::cin.eof())
			return("");
		if (!line.empty() && line.find_first_of(" \t\r") == std::string::npos)
			valid = true;
		else
			std::cout << "Invalid input!" << std::endl;
	}
	
	return (line);
}

/**
 * It reads an index from the user, and returns it
 * 
 * @param str The string to be displayed to the user.
 * 
 * @return The index of the contact to be displayed.
 */
int			PhoneBook::_readIndex(std::string str)
{
	std::string	line;
	int			index;
	bool		valid = false;

	while (!valid)
	{
		std::cout << str << ": ";
		std::getline(std::cin, line);
		std::istringstream(line) >> index;
		if (!std::cin || std::cin.eof())
			return(-1);
		if (!line.empty() && line.find_first_of("0123456789") != std::string::npos)
			valid = true;
		else
			std::cout << "Invalid input!" << std::endl;
	}
	
	return (index);
}

/**
 * It truncates a string to 10 characters and returns it
 * 
 * @param str The string to be truncated.
 * 
 * @return The truncated string.
 */
std::string	PhoneBook::_truncateString(std::string str)
{
	if (str.length() <= 10)
		return (str);
	str.erase(9);
	str.append(".");
	return (str);
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * It reads the user input and stores it in the contact array
 */
void		PhoneBook::addContact(void)
{
	Contact	*contact;

	contact = &this->_contacts[this->_contactCount % 8];
	contact->setValue(std::cin ? _readInput("First name") : "", FIRST_NAME);
	contact->setValue(std::cin ? _readInput("Last name") : "", LAST_NAME);
	contact->setValue(std::cin ? _readInput("Nickname") : "", NICKNAME);
	contact->setValue(std::cin ? _readInput("Phone number") : "", PHONE_NUMBER);
	contact->setValue(std::cin ? _readInput("Darkest secret") : "", DARKEST_SECRET);
	this->_contactCount++;
}

/**
 * It prints the contacts in a table, then asks the user to enter
 * the index of the contact they want to see, and then prints the contact
 */
void		PhoneBook::searchContact(void)
{
	Contact		*contact;
	int 		index = -1;

	if (this->_contactCount == 0)
	{
		std::cout << "No contacts available!" << std::endl;
		return ;
	}
	std::cout << "----------------- Contacts ----------------" << std::endl;
	for (int i = 0; i < 8; i++)
	{
		contact = &this->_contacts[i];
		if (contact->getValue(FIRST_NAME).empty())
			continue ;
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << this->_truncateString(contact->getValue(FIRST_NAME)) << "|";
		std::cout << std::setw(10) << this->_truncateString(contact->getValue(LAST_NAME)) << "|";
		std::cout << std::setw(10) << this->_truncateString(contact->getValue(NICKNAME)) << std::endl;
	}
	while (index == -1)
	{
		index = _readIndex("Enter the index of the contact you want to see");
		if (index == -1)
			return;
		if (index >= 0 && index < 8 && !this->_contacts[index].getValue(FIRST_NAME).empty())
			break;
		std::cout << "Index not found! Please try again." << std::endl;
		index = -1;
	}
	this->_contacts[index].print();
}
