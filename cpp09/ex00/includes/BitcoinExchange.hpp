/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:31:38 by abetemps          #+#    #+#             */
/*   Updated: 2026/07/28 12:33:45 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__BITCOINEXCHANGE_HPP__
# define	__BITCOINEXCHANGE_HPP__

# include <iostream>
# include <stdexcept>
# include <map>

# define PRICES_DB	"data.csv"

class BitcoinExchange
{
	public:
		typedef	std::map<time_t, float>	valuesMap;

		static void					displayWalletHistory(const char *wallet_db_filename);

	private:
		static valuesMap	_stockMarketPrices;

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &cpy);
		~BitcoinExchange(void);
		BitcoinExchange	&operator=(const BitcoinExchange &assign);

		static bool					_isLeapYear(int year);
		static valuesMap			_parseDb(const char *db_filename);
		static char					_parseDbSettings(std::string line);
		static float				_computeValueAtTime(valuesMap::iterator &walletEntry);
};

#endif
