/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 02:44:02 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/27 12:31:52 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>	// std::cout, std::endl

int	main(void)
{
	{
		MutantStack<std::string> test;
		test.push("string1");
		test.push("string2");
		test.push("string3");
		test.push("string4");

		MutantStack<std::string>::iterator sit = test.begin();
		MutantStack<std::string>::iterator eit = test.end();
		while (sit != eit)
			std::cout << *sit++ << std::endl;
	}

	std::cout << std::endl;

	{
		MutantStack<int> test;
		test.push(1);
		test.push(2);
		test.push(3);
		test.push(4);

		MutantStack<int>::iterator sit = test.begin();
		MutantStack<int>::iterator eit = test.end();
		while (sit != eit)
			std::cout << *sit++ << std::endl;
	}

	std::cout << std::endl;

	{
		MutantStack<int> test;
		test.push(1);
		test.push(2);
		test.push(3);
		test.push(4);
		MutantStack<int> tmp(test);
		MutantStack<int> tmp2 = test;

		MutantStack<int>::iterator sit = tmp.begin();
		MutantStack<int>::iterator eit = tmp.end();
		while (sit != eit)
			std::cout << *sit++ << std::endl;

		sit = tmp2.begin();
		eit = tmp2.end();
		while (sit != eit)
			std::cout << *sit++ << std::endl;
	}

	std::cout << std::endl;

	{
		MutantStack<int> mstack;

		mstack.push(5);
		mstack.push(17);

		std::cout << mstack.top() << std::endl;
		
		mstack.pop();

		std::cout << mstack.size() << std::endl;
		
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		
		++it;
		--it;
		while (it != ite) {
			std::cout << *it << std::endl;
			++it; 
		}
		std::stack<int> s(mstack);
	}

	return (0);
}
