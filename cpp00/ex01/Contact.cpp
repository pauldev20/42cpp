/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 23:01:55 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/25 22:58:39 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

/* -------------------------------------------------------------------------- */
/*                                   Getters                                  */
/* -------------------------------------------------------------------------- */

/**
 * It returns the value of the contact's
 * attribute of the type passed as a parameter.
 * 
 * @param type The type of the value to get.
 * 
 * @return The value of the contact at the given index.
 */
std::string	Contact::getValue(t_contact type)
{
	return (this->_values[type]);
}

/**
 * It sets the value of the contact's attribute
 * of type t_contact to the value of the string passed as a parameter
 * 
 * @param value The value to set.
 * @param type The type of the value to set.
 */
void		Contact::setValue(std::string value, t_contact type)
{
	this->_values[type] = value;
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * It prints the contact's information
 */
void		Contact::print(void)
{
	std::cout << "First name: " << this->getValue(FIRST_NAME) << std::endl;
	std::cout << "Last name: " << this->getValue(LAST_NAME) << std::endl;
	std::cout << "Nickname: " << this->getValue(NICKNAME) << std::endl;
	std::cout << "Phone number: " << this->getValue(PHONE_NUMBER) << std::endl;
	std::cout << "Secret: " << this->getValue(DARKEST_SECRET) << std::endl;
}
