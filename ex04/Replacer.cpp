/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:27:11 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/13 18:57:10 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Replacer.hpp"

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

Replacer::Replacer(std::string filename) : _filename(filename)
{
}

Replacer::~Replacer(void)
{
}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

/**
 * It opens the file, reads it, replaces the string, and writes it to a new file
 * 
 * @param s1 The string to be replaced.
 * @param s2 the string to replace s1 with
 * 
 * @return an error code.
 */
int	Replacer::replace(std::string s1, std::string s2)
{
	std::ifstream	inFile(this->_filename.c_str());

	if (inFile.is_open()) {
		std::string	fileContent;
		std::getline(inFile, fileContent, '\0');

		if (!fileContent.empty()) {
			std::ofstream	outFile((this->_filename + ".replace").c_str());

			size_t	pos = fileContent.find(s1);
			while (pos != std::string::npos) {
				fileContent.erase(pos, s1.length());
				fileContent.insert(pos, s2);
				pos = fileContent.find(s1, pos + s2.length());
			}
			outFile << fileContent;
			outFile.close();
		} else {
			std::cout << "Error: File is empty." << std::endl;
		}
		inFile.close();
	} else {
		std::cout << "Error: Could not open file." << std::endl;
		return (1);
	}
	return (0);
}
