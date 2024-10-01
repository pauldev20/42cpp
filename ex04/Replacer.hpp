/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/26 00:27:14 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/26 00:36:12 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REPLACER_HPP
# define REPLACER_HPP

# include <fstream>
# include <iostream>

class Replacer {
	private:
		std::string	_filename;

	public:
		Replacer(std::string filename);
		~Replacer(void);

		int	replace(std::string s1, std::string s2);
};

#endif