/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:34:08 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/27 00:42:53 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>	// std::stack

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack(void) {};
		MutantStack(MutantStack const &src) : std::stack<T>(src) {};
		~MutantStack(void) {};
		MutantStack	&operator=(MutantStack const &rhs) {
			if (*this != rhs)
				*this = rhs;
			return (*this);
		}

		iterator begin() {
			return (std::stack<T>::c.begin());
		}
		iterator end() {
			return (std::stack<T>::c.end());
		}
};

#endif
