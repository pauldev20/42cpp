/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 18:07:17 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/26 22:03:55 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <algorithm>	// std::find

class NoOccurenceFoundException : public std::exception
{
	public:
		virtual const char *what() const throw()
		{
			return ("Occurence Not Found");
		};
};

template <typename T>
typename T::iterator	easyfind(T &hay, int needle)
{
	typename T::iterator it = std::find(hay.begin(), hay.end(), needle);
	if (it == hay.end())
		throw NoOccurenceFoundException();
	return (it);
}

#endif
