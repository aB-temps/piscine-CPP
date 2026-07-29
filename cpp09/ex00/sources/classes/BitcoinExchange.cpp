/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:31:24 by abetemps          #+#    #+#             */
/*   Updated: 2026/07/28 12:31:36 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ctime>
# include <fstream>
# include <sstream>
# include "BitcoinExchange.hpp"

using	std::cout;
using	std::cerr;
using	std::endl;

// Static attr. init -----------------------------------------------------------
BitcoinExchange::BitcoinExchange::valuesMap	BitcoinExchange::_stockMarketPrices = BitcoinExchange::parseDb(PRICES_DB);


// Constructors/Destructor -----------------------------------------------------
BitcoinExchange::BitcoinExchange(void)
{}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	(void) cpy;
}

BitcoinExchange::~BitcoinExchange(void)
{}

// Ops overloading -------------------------------------------------------------
BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &assign)
{
	(void) assign;

	return (*this);
}

// Member Function -------------------------------------------------------------
BitcoinExchange::valuesMap			BitcoinExchange::parseDb(const char *db_filename)
{
	std::ifstream	db(db_filename);
	if (!db.is_open())
		throw (std::invalid_argument(db_filename));
	db.exceptions(std::ios::badbit);


	BitcoinExchange::valuesMap			vmap;
	struct BitcoinExchange::dbSettings	settings;
	std::string							line;

	try
	{
		std::getline(db, line);
		settings = BitcoinExchange::parseDbSettings(line);

		while (std::getline(db, line))
		{
			cout << "line is: " << line << endl;

			size_t				sep_pos = line.find(settings.separator);
			std::stringstream	ss;
			float				value;

			ss << line.find();
			ss >> ;
			vmap[line.substr(0, sep_pos)];
		}

	}
	catch (const std::exception &e)
	{
		cerr << "Fatal error while reading \"" << db_filename << "\" [" << e.what() << "]" << endl;
		throw ;
	}
	// open db_filename, getline to store each line
		// parsing the validity of each one:
			// <date> [YYYY MM DD] | <value> [0, 1000] (float/int)
			// if invalid set first or seconc to errState (date = ?? & value = <0)

	return (vmap);
}

struct BitcoinExchange::dbSettings	BitcoinExchange::parseDbSettings(std::string line)
{
	struct BitcoinExchange::dbSettings	settings;
	size_t	sp_pos = line.find(' ');

	
	settings.fieldA = line.substr(0, sp_pos);
	// cout << settings.fieldA << endl;

	line = line.substr(++sp_pos);
	sp_pos = line.find(' ');
	settings.separator = line.substr(0, sp_pos);
	// cout << settings.separator << endl;

	settings.fieldB = line.substr(++sp_pos); 
	// cout << settings.fieldB << endl;

	return (settings);
}

void				BitcoinExchange::displayWalletHistory(const char *wallet_db_filename)
{
	BitcoinExchange::valuesMap				walletMap = BitcoinExchange::parseDb(wallet_db_filename);

	BitcoinExchange::valuesMap::iterator	walletIt = walletMap.begin();

	for (; walletIt != walletMap.end(); ++walletIt)
	{
		if (/*walletIt->first != errorDate &&*/ walletIt->second >= 0)
		{
			char	tmp_date[10];
			std::strftime(tmp_date, 10, "", std::localtime(&walletIt->first));
			cout << tmp_date << " => " << BitcoinExchange::computeValueAtTime(walletIt) << endl;
		}
	}
}

float				BitcoinExchange::computeValueAtTime(BitcoinExchange::valuesMap::iterator &walletEntry)
{
	float	result = .0;
	float	nearest_value = -1.;

 	if (BitcoinExchange::_stockMarketPrices.count(walletEntry->first))
		nearest_value = BitcoinExchange::_stockMarketPrices[walletEntry->first];
	// else
	// 	nearest_value = std::lower_bound(
	// 			BitcoinExchange::_stockMarketPrices.begin(),
	// 			BitcoinExchange::_stockMarketPrices.end(),
	// 			walletEntry->first)->second;

	result = walletEntry->second * nearest_value;

	return (result);
}
