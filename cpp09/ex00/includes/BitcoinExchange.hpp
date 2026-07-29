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

// # define PRICES_DB	"input.txt"
# define PRICES_DB	"data2.csv"

class BitcoinExchange
{
	public:
		typedef	std::map<time_t, float>	valuesMap;

		struct	dbSettings
		{
			std::string fieldA;
			std::string fieldB;
			std::string separator;
		};

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &cpy);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &assign);

		static void					displayWalletHistory(const char *wallet_db_filename);

		static valuesMap			parseDb(const char *db_filename);
		static struct dbSettings	parseDbSettings(std::string line);

		static float				computeValueAtTime(valuesMap::iterator &walletEntry);


	private:
		static valuesMap	_stockMarketPrices;
};

#endif
