/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:34:08 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/26 03:15:33 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;

		MutantStack(void) {};
		MutantStack(MutantStack const &src) : std::stack<T>(src) {
			*this = src;
		};
		~MutantStack(void) {};
		MutantStack	&operator=(MutantStack const &rhs) {
			(void)rhs;
			return (*this);
		}

		iterator begin() {
			return (std::begin(std::stack<T>::c));
		}
		iterator end() {
			return (std::end(std::stack<T>::c));
		}
};

#endif
