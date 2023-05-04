/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 13:18:45 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/04 02:13:02 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <sys/time.h>
#include <algorithm>
#include <sstream>
#include <utility>

/* -------------------------------------------------------------------------- */
/*                                   Helpers                                  */
/* -------------------------------------------------------------------------- */

/* The `printContainer` function is a template function that takes a string `text` and a container of
type `T` as arguments. It prints the string `text` followed by a colon and a space, and then
iterates through the container using a const iterator. For each element in the container, it prints
the element followed by a space. Finally, it prints a newline character. The function is used to
print the contents of a container to the console. The `typename` keyword is used to specify that
`T::const_iterator` is a type, since `T` is a template parameter and the compiler cannot know
whether `const_iterator` is a type or a member variable without the `typename` keyword. */
template <typename T>
void	printContainer(std::string const &text, T const &container)
{
	std::cout << text << "\t";
	for (typename T::const_iterator it = container.begin(); it != container.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

/* The `binaryInsertion` function is a template function that takes a reference to a vector of type `T`
and a value of type `T` as arguments. It performs a binary search on the vector to find the correct
position to insert the value, and then inserts the value at that position using the `insert`
function of the vector. The function is used in the `sortVector` function to insert pairs of values
in a sorted order. */
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

/**
 * The function returns the current time in microseconds using the gettimeofday function.
 * 
 * @return The function `getTime()` returns the current time in microseconds since the Epoch (January
 * 1st, 1970, 00:00:00 UTC) as a `time_t` data type.
 */
time_t	getTime(void)
{
	struct timeval tp;
	gettimeofday(&tp, NULL);
	return (tp.tv_sec * 1000000 + tp.tv_usec);
}

/**
 * The function prints the time difference between two time_t variables in either milliseconds or
 * microseconds, depending on the value of the difference.
 * 
 * @param msg A string message to be printed before the time measurement.
 * @param start The starting time in seconds since the Unix epoch (January 1, 1970).
 * @param end The "end" parameter is a variable of type time_t that represents the end time of a
 * process or operation. It is used in conjunction with the "start" parameter to calculate the duration
 * of the process or operation.
 */
void	printTime(std::string const &msg, time_t start, time_t end)
{
	time_t diff = end - start;
	std::cout << msg << " \t: ";
	std::cout << ((diff > 10000) ? diff / 1000 : diff);
	std::cout << ((diff > 10000) ? " ms" : " µs") << std::endl;
}

/* The `execAndPrint` function is a template function that takes four arguments: a string `type`, an
integer `size`, a function pointer `func` that takes no arguments and returns a value of type `T`,
and a boolean `print` that defaults to `true`. The function is used to execute a function `func` and
print the results and the time it took to execute the function. */
template <typename T>
void	execAndPrint(std::string const &type, int64_t size, T (*func)(void), bool print = true)
{
	time_t start = getTime();
	T ret = func();
	time_t end = getTime();
	if (print)
		printContainer("After: ", ret);
	std::ostringstream s;
	s << "Time to process a range of " << size << " elements with " << type;
	printTime(s.str(), start, end);
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

/**
 * The function sorts a list of integers using std::set and std::vector and prints the results.
 * 
 * @param argc The number of arguments passed to the function, including the name of the program.
 * @param argv The argv parameter is a pointer to an array of C-style strings (char arrays) that
 * represent the command line arguments passed to the program. In this case, the function is using the
 * values in argv to sort a vector of integers.
 */
void PmergeMe::sort(int argc, char **argv)
{
	for (int i = 1; i < argc; i++)
		if (std::string(argv[i]).find_first_not_of("0123456789") != std::string::npos)
			throw PmergeMe::InvalidInputException();

	for (int i = 1; i < argc; i++) {
		int64_t intVal;
		std::ostringstream tmp;
		std::istringstream(argv[i]) >> intVal;
		tmp << intVal;
		if (tmp.str() != argv[i])
			throw PmergeMe::InvalidInputException();

		bool	found = false;
		for (std::vector<int64_t>::iterator its = _vec.begin(); its != _vec.end(); ++its) {
			if (*its == intVal)
				found = true;
		}
		if (!found)
			_vec.push_back(intVal);
	}

	printContainer("Before:", _vec);

	execAndPrint("std::set", _vec.size(), sortSet);
	execAndPrint("std::vector", _vec.size(), sortVector, false);
}

/**
 * The function sorts a vector of integers using a set and the merge insertion sortalgorithm
 * and returns a set of unique sorted integers.
 * 
 * @return The function `sortSet` returns a `std::set` of `int64_t` values, which contains the sorted
 * and unique elements of the `_vec` vector.
 */
std::set<int64_t>	PmergeMe::sortSet(void)
{
	int64_t										tmp;
	std::set<std::pair<int64_t, int64_t> >		pairsSet;
	std::set<int64_t>							returnSet;

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

/**
 * The function sorts a vector of integers using the
 * merge insertion sort algorithm and returns the sorted vector.
 * 
 * @return A sorted vector of integers.
 */
std::vector<int64_t>	PmergeMe::sortVector(void)
{
	int64_t										tmp;
	std::vector<std::pair<int64_t, int64_t> >	pairsVector;
	std::vector<int64_t>						returnVector;
	int64_t										*lastElement = NULL;

	if (_vec.size() % 2 != 0)
		lastElement = &_vec.back();
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
	if (lastElement != NULL)
		binaryInsertion(returnVector, *lastElement);

	return (returnVector);
}

/* -------------------------------------------------------------------------- */
/*                                  Exception                                 */
/* -------------------------------------------------------------------------- */

const char *PmergeMe::InvalidInputException::what() const throw()
{
	return ("The input provided is invalid");
}
