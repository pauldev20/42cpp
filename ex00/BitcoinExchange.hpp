/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pgeeser <pgeeser@student.42heilbronn.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 01:23:35 by pgeeser           #+#    #+#             */
/*   Updated: 2023/05/02 19:16:33 by pgeeser          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <string>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange(std::string	const &database);
		BitcoinExchange(BitcoinExchange const &src);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(BitcoinExchange const &rhs);

		void	parseInputFile(std::string const &path);

		class InvalidInputFileException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidDatabaseException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidDateException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

		class InvalidValueException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:
		std::map<time_t, float>	data;
		BitcoinExchange(void);
};

#endif
