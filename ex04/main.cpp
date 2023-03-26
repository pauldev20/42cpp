/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:20:50 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/26 00:42:38 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

int	main(int argc, char **argv)
{

	if (argc != 4) {
		std::cout << "Usage: ./replacer <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	Replacer replacer(argv[1]);
	if (replacer.replace(argv[2], argv[3])) {
		return (1);
	}
	return (0);
}
