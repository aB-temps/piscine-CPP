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
			cout << "line: " << line << endl;

			size_t				sep_pos = line.find(settings.separator);
			std::stringstream	ss;
			float				value;
			std::tm				tm = {};

			strptime(line.substr(0, sep_pos).c_str(), "%04Y-%02m-%02d", &tm);

			ss << line.substr(sep_pos + 1);
			ss >> value;

			cout << "mktime: " << std::mktime(&tm) << endl;
			cout << "time: '" << line.substr(0, sep_pos) << "'" << endl;
			cout << "value: '" << value << "'\n" << endl;

			vmap[std::mktime(&tm)] = value;
		}

	}
	catch (const std::exception &e)
	{
		cerr << "Fatal error while reading \"" << db_filename << "\" [" << e.what() << "]" << endl;
		throw 1;
	}
	// open db_filename, getline to store each line
		// parsing the validity of each one:
			// <date> [YYYY MM DD] | <value> [0, 1000] (float/int)
			// if invalid set first or seconc to errState (date = ?? & value = <0)

	return (vmap);
}

struct BitcoinExchange::dbSettings	BitcoinExchange::parseDbSettings(std::string line)
{
	const char							*allowedSeparator = ",|/";
	struct BitcoinExchange::dbSettings	settings;
	size_t								sep_pos = std::string::npos;

	for (int i = 0; i < 3 && sep_pos == std::string::npos; ++i)
		sep_pos = line.find(allowedSeparator[i]);
	if (sep_pos == std::string::npos)
		throw (std::invalid_argument("wrong separator in file header"));

	settings.separator = line.substr(sep_pos, 1);
	// cout << "Separator: " << settings.separator << endl;

	// settings.fieldA = line.substr(0, sp_pos);
	// cout << settings.fieldA << endl;
	//
	//
	// settings.fieldB = line.substr(++sp_pos); 
	// cout << settings.fieldB << endl;
	//
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
			char	tmp_date[11];
			std::strftime(tmp_date, 11, "%04Y-%02m-%02d", std::localtime(&walletIt->first));
			cout << tmp_date << " => " << BitcoinExchange::computeValueAtTime(walletIt) << endl;
		}
	}
}

float				BitcoinExchange::computeValueAtTime(BitcoinExchange::valuesMap::iterator &walletEntry)
{
	float	nearest_value = .0;

 	if (BitcoinExchange::_stockMarketPrices.count(walletEntry->first))
		nearest_value = BitcoinExchange::_stockMarketPrices[walletEntry->first];
	else
	{
		cerr << "not found" << endl;
		// nearest_value = std::lower_bound(
		// 		BitcoinExchange::_stockMarketPrices.begin(),
		// 		BitcoinExchange::_stockMarketPrices.end(),
		// 		walletEntry->first)->second;
	}

	cout << "\nnearest: " << nearest_value << endl;
	cout << "date: " << walletEntry->first << endl;
	cout << "value: " << walletEntry->second << endl << "result: ";

	float	result = walletEntry->second * nearest_value;

	return (result);
}
