/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:54:09 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/15 18:04:18 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class Ice : public AMateria
{
	public:
		Ice(void);
		Ice(Ice const &src);
		~Ice(void);
		Ice	&operator=(Ice const &rhs);

		AMateria	*clone(void) const;
		void		use(ICharacter &target);
};

#endif
