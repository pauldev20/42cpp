/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:09:06 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/04 01:13:26 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>	// std::cout, std::endl

int	main(int argc, char **argv)
{
	if (argc < 2) {
		std::cout << "Usage: ./pmergeme <integers>" << std::endl;
		return (1);
	}

	try {
		PmergeMe::sort(argc, argv);
	} catch (const std::exception &exce) {
		std::cout << "Error: " << exce.what() << std::endl;
	}

	return (0);
}
