/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:38:48 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/26 13:30:01 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>	// std::cout, std::endl

int main(void)
{
	Data		*data = new Data;
	data->str1 = "Hello";
	data->str2 = "World!";

	std::cout << "Input: " << data->str1 << " " << data->str2 << std::endl;

	uintptr_t	serialized = Serializer::serialize(data);
	std::cout << "Serialized: " << serialized << std::endl;

	Data		*deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized->str1 << " " << deserialized->str2 << std::endl;

	if (data == deserialized)
		std::cout << "The pointers are equal!" << std::endl;
	else
		std::cout << "The pointers are not equal!" << std::endl;
	delete data;

	return (0);
}
