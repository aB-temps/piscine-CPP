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
	std::string							line;

	try
	{
		std::getline(db, line);
		char	separator = BitcoinExchange::parseDbSettings(line);

		for (size_t i = 1; std::getline(db, line); ++i)
		{
			if (line[0] == '#')
				continue;
			// cout << "line: " << line << endl;

			size_t				sep_pos = line.find(separator);
			std::stringstream	ss;
			float				value;
			std::tm				tm = {};

			if (!strptime(line.substr(0, sep_pos).c_str(), "%04Y-%02m-%02d", &tm) || 
					(tm.tm_mon == 1 && (tm.tm_mday > 29 || 
										(tm.tm_mday == 29 && !BitcoinExchange::isLeapYear(tm.tm_year)))))
			{
				cerr << "Error: bad input => '" << line.substr(0, sep_pos) << "' [" << db_filename << ":line "<< i << "]" << endl;
				continue;
			}

			ss << line.substr(sep_pos + 1);
			ss >> value;

			// cout << "mktime: " << std::mktime(&tm) << endl;
			// cout << "time: '" << line.substr(0, sep_pos) << "'" << endl;
			// cout << "value: '" << value << "'\n" << endl;

			vmap[std::mktime(&tm)] = value;
		}

		if (!vmap.size())
			cerr << "Error: " << db_filename << " do not contain any exploitable data." << endl;
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

char	BitcoinExchange::parseDbSettings(std::string line)
{
	const char							*allowedSeparator = ",|/";
	size_t								sep_pos = std::string::npos;

	for (int i = 0; i < 3 && sep_pos == std::string::npos; ++i)
		sep_pos = line.find(allowedSeparator[i]);
	if (sep_pos == std::string::npos)
		throw (std::invalid_argument("wrong separator in file header"));

	return (line.substr(sep_pos, 1).c_str()[0]);
}

void				BitcoinExchange::displayWalletHistory(const char *wallet_db_filename)
{
	BitcoinExchange::valuesMap				walletMap = BitcoinExchange::parseDb(wallet_db_filename);
	BitcoinExchange::valuesMap::iterator	walletIt = walletMap.begin();

	for (size_t i = 1; walletIt != walletMap.end(); ++i,  ++walletIt)
	{
		if (walletIt->second < 0)
			cerr << "Error: value '" << walletIt->second << "': not a positive number. [" << wallet_db_filename << ":line " << i << "]" << endl;
		else if (walletIt->second > 1000)
			cerr << "Error: value '" << walletIt->second << "': a too large number. [" << wallet_db_filename << ":line "<< i << "]" << endl;
		else
		{
			char	tmp_date[11];
			std::strftime(tmp_date, 11, "%04Y-%02m-%02d", std::localtime(&walletIt->first));
			cout << tmp_date << " => " << BitcoinExchange::computeValueAtTime(walletIt) << endl;
		}
	}
}

float				BitcoinExchange::computeValueAtTime(BitcoinExchange::valuesMap::iterator &walletEntry)
{
	float	valueAtTime = .0;

 	if (BitcoinExchange::_stockMarketPrices.count(walletEntry->first))
		valueAtTime = BitcoinExchange::_stockMarketPrices[walletEntry->first];
	else
	{
		BitcoinExchange::valuesMap::iterator	nearestEntry = --(std::lower_bound(
				BitcoinExchange::_stockMarketPrices.begin(),
				BitcoinExchange::_stockMarketPrices.end(),
				*walletEntry));
		valueAtTime = nearestEntry->second;
	}

	float	result = walletEntry->second * valueAtTime;

	return (result);
}

bool			BitcoinExchange::isLeapYear(int year)
{
	if (year % 4 == 0 || year % 400 == 0)
		return (true);
	else
		return (false);
}
