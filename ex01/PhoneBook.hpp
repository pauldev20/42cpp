/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:45:01 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/13 18:32:33 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>

# include "Contact.hpp"

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class PhoneBook
{
	private:
		Contact 	_contacts[8];
		int			_contactCount;

		int			_readIndex(std::string str);
		std::string	_readInput(std::string str, char const *allowed);
		std::string	_truncateString(std::string str);

	public:
		PhoneBook(void);
		~PhoneBook(void);

		void addContact(void);
		void searchContact(void);
};

#endif
