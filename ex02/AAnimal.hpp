/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 15:34:47 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/07 19:46:32 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

# include <iostream>

class AAnimal
{
	protected:
		std::string	type;

	public:
		AAnimal(void);
		AAnimal(AAnimal const &src);
		virtual ~AAnimal(void);
		AAnimal	&operator=(AAnimal const &rhs);

		std::string		getType(void) const;
		virtual void	makeSound(void) const =0;
};

#endif
