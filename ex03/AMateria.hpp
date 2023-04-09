/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:43:37 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/09 02:33:13 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <iostream>

# include "ICharacter.hpp"

class ICharacter;

class AMateria
{
	protected:
		std::string const _type;

	public:
		AMateria(std::string const & type);
		AMateria(AMateria const &src);
		virtual ~AMateria(void);
		AMateria	&operator=(AMateria const &rhs);

		std::string const &getType() const; //Returns the materia type

		virtual AMateria* clone() const =0;
		virtual void use(ICharacter& target);
};

#endif
