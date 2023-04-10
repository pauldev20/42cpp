/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:26:23 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/10 19:39:47 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span {
	private:
		unsigned int		_size;
		unsigned int		_pos;
		std::vector<int>	_vec;

	public:
		Span();
		Span(unsigned int N);
		Span(Span const &src);
		~Span();
		Span &operator=(Span const &rhs);

		void	addNumber(int nb);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		class TooManyElementsException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
