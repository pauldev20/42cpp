/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:50:51 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/04 01:25:46 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>	// std::cout, std::endl

int	main(int argc, char **argv)
{
	if (argc != 2 || std::string(argv[1]).empty()) {
		std::cout << "Usage: ./RPN <mathematical expression>" << std::endl;
		return (1);
	}

	try {
		std::cout << RPN::calculate(argv[1]) << std::endl;
	} catch (std::exception &exec) {
		std::cout << "Error: " << exec.what() << std::endl;
		return (1);
	}

	return (0);	
}
