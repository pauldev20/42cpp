/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:26 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/04 02:33:49 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>		// std::string
# include <stack>		// std::stack
# include <stdint.h>	// int_fast64_t

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class RPN
{
	public:
		~RPN(void);

		static int calculate(std::string const &expression);

		class InvalidCharacterException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class TooShortInputException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidInputException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class DivisionByZeroException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		static std::stack<int_fast64_t> _operations;

		RPN(void);
		RPN(RPN const &src);
		RPN	&operator=(RPN const &rhs);
};

#endif
