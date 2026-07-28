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

# define PRICES_DB	"data.csv"

class BitcoinExchange
{
	public:
		typedef	std::map<time_t, float>	valuesMap;

		BitcoinExchange(void);
		BitcoinExchange(const BitcoinExchange &cpy);
		~BitcoinExchange(void);

		BitcoinExchange	&operator=(const BitcoinExchange &assign);

		static void			displayWalletHistory(const char *wallet_db_filename);

		static valuesMap	parseDb(const char *db_filename);
		float				computeValueAtTime(const valuesMap::iterator *walletEntry);

	private:
		static valuesMap	_stockMarketPrices;
};

#endif
