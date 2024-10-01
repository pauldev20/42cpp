/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:07:32 by pgeeser           #+#    #+#             */
/*   Updated: 2023/04/14 00:15:53 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class Fixed {
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(Fixed const &src);
		~Fixed();

		Fixed &operator=(Fixed const &rhs);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
};

#endif
