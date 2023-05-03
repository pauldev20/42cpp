/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 01:53:26 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/03 01:57:40 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <string>
# include <stack>

class RPN
{
	public:
		~RPN(void);

		static void calculate(std::string const &expression);

	private:
		static std::stack<int64_t> operations;

		RPN(void);
		RPN(RPN const &src);
		RPN	&operator=(RPN const &rhs);
};

#endif
