/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:18:45 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/03 16:16:21 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sstream>
#include <algorithm>
#include <utility>

/* -------------------------------------------------------------------------- */
/*                                   Helpers                                  */
/* -------------------------------------------------------------------------- */

template <typename T>
void	binaryInsertion(std::vector<T> &vec, T val)
{
	int64_t	low = 0;
	int64_t high = vec.size() - 1;
	while (low <= high) {
		int64_t mid = (low + high) / 2;
		if (val < vec[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	typename std::vector<T>::iterator insertionPosition = vec.begin() + low;
	vec.insert(insertionPosition, val);
}

/* -------------------------------------------------------------------------- */
/*                           Statics Initializiation                          */
/* -------------------------------------------------------------------------- */

std::vector<int64_t> PmergeMe::_vec;

/* -------------------------------------------------------------------------- */
/*                                Class Methods                               */
/* -------------------------------------------------------------------------- */

PmergeMe::~PmergeMe(void) {}

/* -------------------------------------------------------------------------- */
/*                               Public Methods                               */
/* -------------------------------------------------------------------------- */

void PmergeMe::sort(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
			throw std::exception();

	for (int i = 1; i < argc; i++) {
		int64_t intVal;
		std::ostringstream tmp;
		std::istringstream(argv[i]) >> intVal;
		tmp << intVal;
		if (tmp.str() != argv[i])
			throw std::exception();

		for (std::vector<int64_t>::iterator its = _vec.begin(); its != _vec.end(); ++its) {
			if (*its == intVal)
				throw std::exception();
		}
		_vec.push_back(intVal);
	}

	std::cout << "Before: ";
	for (std::vector<int64_t>::iterator its = _vec.begin(); its != _vec.end(); ++its)
		std::cout << *its << " ";
	std::cout << std::endl;
	
	std::set<int64_t>		sortedSet = sortSet();
	std::vector<int64_t>	sortedVector = sortVector();
	
	std::cout << "After: ";
	for (std::set<int64_t>::iterator its = sortedSet.begin(); its != sortedSet.end(); ++its)
		std::cout << *its << " ";
	std::cout << std::endl;
	std::cout << "Vector After: ";
	for (std::vector<int64_t>::iterator its = sortedVector.begin(); its != sortedVector.end(); ++its)
		std::cout << *its << " ";
	std::cout << std::endl;
}

std::set<int64_t>	PmergeMe::sortSet(void)
{
	int64_t										tmp;
	std::set<int64_t>							returnSet;
	std::set<std::pair<int64_t, int64_t> >		pairsSet;

	for (std::vector<int64_t>::iterator its = _vec.begin(); its != _vec.end(); ++its) {
		tmp = *its++;
		if (its == _vec.end()) {
			returnSet.insert(tmp);
			break;
		}
		if (tmp < *its)
			pairsSet.insert(std::make_pair(tmp, *its));
		else
			pairsSet.insert(std::make_pair(*its, tmp));
	}

	for (std::set<std::pair<int64_t, int64_t> >::iterator its = pairsSet.begin(); its != pairsSet.end(); ++its) {
		returnSet.insert(its->first);
	}
	for (std::set<std::pair<int64_t, int64_t> >::iterator its = pairsSet.begin(); its != pairsSet.end(); ++its) {
		returnSet.insert(its->second);
	}

	return(returnSet);
}

std::vector<int64_t>	PmergeMe::sortVector(void)
{
	int64_t										tmp;
	int64_t										lastElement = -1;
	std::vector<int64_t>						returnVector;
	std::vector<std::pair<int64_t, int64_t> >	pairsVector;

	if (_vec.size() % 2 != 0)
		lastElement = _vec.back();
	for (std::vector<int64_t>::iterator its = _vec.begin(); its != _vec.end(); ++its) {
		tmp = *its++;
		if (its == _vec.end())
			break;
		if (tmp < *its)
			binaryInsertion(pairsVector, std::make_pair(tmp, *its));
		else
			binaryInsertion(pairsVector, std::make_pair(*its, tmp));
	}

	for (std::vector<std::pair<int64_t, int64_t> >::iterator its = pairsVector.begin(); its != pairsVector.end(); ++its) {
		returnVector.push_back(its->first);
	}
	for (std::vector<std::pair<int64_t, int64_t> >::iterator its = pairsVector.begin(); its != pairsVector.end(); ++its) {
		binaryInsertion(returnVector, its->second);
	}
	if (lastElement != -1)
		binaryInsertion(returnVector, lastElement);

	return (returnVector);
}
