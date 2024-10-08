/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:34:47 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 15:42:00 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class Animal
{
	protected:
		std::string	type;

	public:
		Animal(void);
		Animal(Animal const &src);
		virtual ~Animal(void);
		Animal	&operator=(Animal const &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const;
};

#endif
