/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 18:22:15 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/07 18:29:09 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
	protected:
		std::string	type;

	public:
		WrongAnimal(void);
		WrongAnimal(WrongAnimal const &src);
		~WrongAnimal(void);
		WrongAnimal	&operator=(WrongAnimal const &rhs);

		std::string		getType(void) const;
		void	makeSound(void) const;
};

#endif
