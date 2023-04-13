/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 17:39:11 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/13 15:58:10 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

/**
 * It reads a line from the standard input, and if it's "ADD", it calls the addContact() function, if
 * it's "SEARCH", it calls the searchContact() function, and if it's "EXIT", it prints "Goodbye!" and
 * exits the program
 * 
 * @return The return value is the exit status of the program.
 */
int	main(void)
{
	std::string	line;
	PhoneBook 	phonebook;

	while (line != "EXIT" && std::cin)
	{
		std::cout << "> ";
		std::getline(std::cin, line);
		if (line == "ADD")
			phonebook.addContact();
		else if (line == "SEARCH")
			phonebook.searchContact();
		else if (line == "EXIT")
			std::cout << "Goodbye!" << std::endl;
	}
	return (0);
}
