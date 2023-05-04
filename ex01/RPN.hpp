/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:26 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/04 02:06:32 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>		// std::string
# include <stack>		// std::stack
# include <stdint.h>	// int64_t

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class RPN
{
	public:
		~RPN(void);

		static int64_t calculate(std::string const &expression);

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
		static std::stack<int64_t> _operations;

		RPN(void);
		RPN(RPN const &src);
		RPN	&operator=(RPN const &rhs);
};

#endif
