/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 23:49:46 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/25 23:54:06 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main(void)
{
	std::string	str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "string address: \t" << &str << std::endl;
	std::cout << "stringPTR address: \t" << stringPTR << std::endl;
	std::cout << "stringREF address: \t" << &stringREF << std::endl;

	std::cout << "string value: \t\t" << str << std::endl;
	std::cout << "stringPTR value: \t" << *stringPTR << std::endl;
	std::cout << "stringREF value: \t" << stringREF << std::endl;
	return (0);
}