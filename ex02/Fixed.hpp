/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 23:07:32 by pgeeser           #+#    #+#             */
/*   Updated: 2023/03/28 03:23:54 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

#include <iostream>

/* -------------------------------------------------------------------------- */
/*                                   Classes                                  */
/* -------------------------------------------------------------------------- */

class Fixed {
	private:
		int					_value;
		static const int	_fractionalBits;

	public:
		Fixed();
		Fixed(int const value);
		Fixed(float const value);
		Fixed(Fixed const &src);
		Fixed	&operator=(Fixed const &rhs);
		~Fixed();

		bool 				operator>(Fixed const &rhs) const;
		bool 				operator<(Fixed const &rhs) const;
		bool 				operator<=(Fixed const &rhs) const;
		bool 				operator>=(Fixed const &rhs) const;
		bool 				operator==(Fixed const &rhs) const;
		bool 				operator!=(Fixed const &rhs) const;
		Fixed 				operator+(Fixed const &rhs) const;
		Fixed 				operator-(Fixed const &rhs) const;
		Fixed 				operator*(Fixed const &rhs) const;
		Fixed 				operator/(Fixed const &rhs) const;
		Fixed 				&operator++(void);
		Fixed 				&operator--(void);
		Fixed 				operator++(int);
		Fixed 				operator--(int);

		int					getRawBits(void) const;
		void				setRawBits(int const raw);

		float 				toFloat(void) const;
		int					toInt(void) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static Fixed const	&min(Fixed const &a, Fixed const &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static Fixed const	&max(Fixed const &a, Fixed const &b);
};

std::ostream	&operator<<(std::ostream &os, Fixed const &person);

#endif
