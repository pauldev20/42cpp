/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:24:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 20:35:37 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter();

	public:
		ScalarConverter(ScalarConverter const &src);
		~ScalarConverter();
		ScalarConverter		&operator=(ScalarConverter const &rhs);

		static void			convert(std::string const input);

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
