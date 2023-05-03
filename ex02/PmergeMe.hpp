/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:16:03 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/03 15:19:21 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP
 
# include <iostream>	// std::cout, std::endl, std::string
# include <vector>		// std::vector
# include <set>			// std::set

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class PmergeMe
{
	public:
		~PmergeMe(void);
		static void	sort(int argc, char **argv);

	private:
		static std::vector<int64_t> _vec;

		PmergeMe(void);
		PmergeMe(PmergeMe const &src);
		PmergeMe &operator=(PmergeMe const &rhs);

		static std::set<int64_t>	sortSet(void);
		static std::vector<int64_t>	sortVector(void);
};

#endif