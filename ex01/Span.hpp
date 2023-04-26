/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 19:26:23 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/26 20:58:56 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <vector>	// std::vector

# define ABS(a) (((a) < 0) ? (-(a)) : ((a)))

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class Span {
	private:
		unsigned int		_size;
		unsigned int		_pos;
		std::vector<int>	_vec;
		Span(void);

	public:
		Span(unsigned int N);
		Span(Span const &src);
		~Span(void);
		Span &operator=(Span const &rhs);

		void	addNumber(int nb);
		int		shortestSpan(void) const;
		int		longestSpan(void) const;

		template <typename Iterator>
		void	addNumber(Iterator begin, Iterator end) {
			if (end - begin > _size)
				throw TooManyElementsException();
			std::copy(begin, end, std::back_inserter(this->_vec));
		}

		class TooManyElementsException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class NoSpanCanBeFoundException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
