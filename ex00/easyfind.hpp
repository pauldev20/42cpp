/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:07:17 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/10 18:30:23 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>

class NoOccurenceFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Occurence Not Found");
		};
};

template <typename T>
typename T::iterator	easyfind(T &a, int b)
{
	typename T::iterator it;

	it = std::find(a.begin(), a.end(), b);
	if (it == a.end())
		throw NoOccurenceFoundException();
	return (it);
}

#endif
