/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 20:35:55 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 20:36:37 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int		main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./convert <input>" << std::endl;
		return (1);
	}

	try
	{
		ScalarConverter::convert(argv[1]);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
