/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:24:20 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/24 21:57:06 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>

class ScalarConverter
{
	private:
		ScalarConverter(void);
		ScalarConverter(ScalarConverter const &src);
		ScalarConverter		&operator=(ScalarConverter const &rhs);

	public:
		~ScalarConverter(void);

		static void			convert(std::string const input);

		class InvalidInputException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
