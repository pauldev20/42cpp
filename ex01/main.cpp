/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 13:38:48 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/10 13:44:30 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main(void)
{
	Data		*data = new Data;

	data->str1 = "Hello";
	data->str2 = "World!";

	uintptr_t	serialized = Serializer::serialize(data);
	std::cout << "Serialized: " << serialized << std::endl;
	Data		*deserialized = Serializer::deserialize(serialized);
	std::cout << "Deserialized: " << deserialized->str1 << " " << deserialized->str2 << std::endl;
	delete data;

	return (0);
}
