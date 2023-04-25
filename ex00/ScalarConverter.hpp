/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:24:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/25 15:28:16 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>	// std::string

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter		&operator=(ScalarConverter const &rhs);
		~ScalarConverter(void);

		static bool			handlePseudo(std::string const &input);
		static void			printOutput(std::string input, std::string const &charVal, int const &intVal, float const &floatVal, double const &doubleVal);
		static void			handleInputError(std::string const &input);

	public:
		static void			convert(std::string const &input);

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class OverflowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
