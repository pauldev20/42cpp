/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:40:14 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 17:34:42 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "AAnimal.hpp"
# include "Brain.hpp"

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class Cat : public AAnimal
{
	private:
		Brain	*brain;

	public:
		Cat();
		Cat(Cat const &src);
		~Cat();
		Cat	&operator=(Cat const &rhs);

		void	makeSound(void) const;
};

#endif
