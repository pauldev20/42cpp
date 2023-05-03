/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:09:06 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/03 13:25:06 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>	// std::cout, std::endl

int	main(int argc, char **argv)
{
	try {
		PmergeMe::sort(argc, argv);
	} catch (const std::exception &exce) {
		std::cout << "Error: " << exce.what() << std::endl;
	}

	return (0);
}
