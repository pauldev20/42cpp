/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:24:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/10 00:12:09 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter		&operator=(ScalarConverter const &rhs);

	public:
		~ScalarConverter();

		static void			convert(std::string const input);

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
