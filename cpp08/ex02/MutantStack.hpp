/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:34:08 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/27 13:14:55 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <stack>	// std::stack

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator 				iterator;
		typedef typename std::stack<T>::container_type::const_iterator 			const_iterator;
		typedef typename std::stack<T>::container_type::reverse_iterator 		reverse_iterator;
		typedef typename std::stack<T>::container_type::const_reverse_iterator 	const_reverse_iterator;

		MutantStack(void) {};
		MutantStack(MutantStack const &src) : std::stack<T>(src) {};
		~MutantStack(void) {};
		MutantStack	&operator=(MutantStack const &rhs) {
			if (*this != rhs)
				*this = rhs;
			return (*this);
		}

		iterator begin(void) {
			return (this->c.begin());
		}
		iterator end(void) {
			return (this->c.end());
		}

		const_iterator begin(void) const {
			return (this->c.begin());
		}
		const_iterator end(void) const {
			return (this->c.end());
		}

		reverse_iterator rbegin(void) {
			return (this->c.rbegin());
		}
		reverse_iterator rend(void) {
			return (this->c.rend());
		}

		const_reverse_iterator rbegin(void) const {
			return (this->c.rbegin());
		}
		const_reverse_iterator rend(void) const {
			return (this->c.rend());
		}
};

#endif
