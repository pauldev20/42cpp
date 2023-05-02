/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 00:56:52 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/02 19:15:55 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <iostream>	// std::cout, std::endl

int	main(int argc, char **argv)
{
	if (argc != 2) {
		std::cout << "Usage: ./btc <input.txt>" << std::endl;
		return (1);
	}
	try {
		BitcoinExchange btc("./data.csv");
		btc.parseInputFile(argv[1]);
	} catch (std::exception &exec) {
		std::cout << exec.what() << std::endl;
		return (1);
	}
	return (0);
}
