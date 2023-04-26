/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:14:48 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/26 20:38:37 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <iostream>
#include <vector>

int	main(void)
{
	std::vector<int> numbers;
	numbers.push_back(1);
	numbers.push_back(100);
	numbers.push_back(10);
	numbers.push_back(70);
	numbers.push_back(100);

	try {
		std::cout << *(::easyfind(numbers, 33)) << std::endl;
	} catch (std::exception &exec) {
		std::cout << exec.what() << std::endl;
	}
	std::cout << *(::easyfind(numbers, 70)) << std::endl;

	return (0);
}
