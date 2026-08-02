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
# include <algorithm>
# include "BitcoinExchange.hpp"

using	std::cout;
using	std::cerr;
using	std::endl;

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
void				BitcoinExchange::displayWalletHistory(const char *wallet_db_filename)
{
	static valuesMap	stockMarketPrices = _parseDb(PRICES_DB);
	cout << "For wallet \"" << wallet_db_filename << "\":\n";

	valuesMap				walletMap = _parseDb(wallet_db_filename);
	valuesMap::iterator		walletIt = walletMap.begin();

	for (size_t i = 1; walletIt != walletMap.end(); ++i,  ++walletIt)
	{
		if (walletIt->second < 0)
			cerr << "Error: value '" << walletIt->second << "': not a positive number. [" << wallet_db_filename << ":line " << i << "]" << endl;
		else if (walletIt->second > 1000)
			cerr << "Error: value '" << walletIt->second << "': too large number. [" << wallet_db_filename << ":line "<< i << "]" << endl;
		else
		{
			char	tmp_date[11];
			std::strftime(tmp_date, 11, "%04Y-%02m-%02d", std::localtime(&walletIt->first));
			cout << tmp_date << " => " << BitcoinExchange::_computeValueAtTime(walletIt, stockMarketPrices) << endl;
		}
	}
}

BitcoinExchange::valuesMap			BitcoinExchange::_parseDb(const char *db_filename)
{
	std::ifstream	db(db_filename);
	if (!db.is_open())
		throw (std::runtime_error(db_filename));
	db.exceptions(std::ios::badbit);


	valuesMap	vmap;
	std::string	line;

	try
	{
		std::getline(db, line);
		char	separator = _parseDbSettings(line);
		if (std::string(db_filename) == PRICES_DB && separator != ',')
			throw (std::invalid_argument("invalid separator"));

		for (size_t i = 1; std::getline(db, line); ++i)
		{
			if (line[0] == '#')
				continue;

			size_t				sep_pos = line.find(separator);
			if (sep_pos == std::string::npos)
			{
				cerr	<< "Error: bad input => '" << line.substr(0, sep_pos) 
						<< "': separator '" << separator << "' not found [" << db_filename << ":line "<< i << "]" << endl;
				continue;
			}
			std::stringstream	ss;
			float				value;
			std::tm				tm = {};

			if (!strptime(line.substr(0, sep_pos).c_str(), "%04Y-%02m-%02d", &tm) || 
					(tm.tm_mon == 1 && (tm.tm_mday > 29 || 
										(tm.tm_mday == 29 && !_isLeapYear(tm.tm_year)))))
			{
				cerr << "Error: bad input => '" << line.substr(0, sep_pos) << "' [" << db_filename << ":line "<< i << "]" << endl;
				continue;
			}

			ss << line.substr(sep_pos + 1);
			ss >> value;

			vmap[std::mktime(&tm)] = value;
		}

		if (!vmap.size())
		{
			if (std::string(db_filename) == PRICES_DB)
				throw (std::invalid_argument("not any exploitable data"));
			else
				cerr << "File \"" << db_filename <<  "\": do not contain any exploitable data" << endl;
		}
	}
	catch (const std::invalid_argument &e)
	{
		cerr << "Parsing error: " << e.what() << " [" << db_filename << "]" << endl;
		throw;
	}
	catch (const std::runtime_error &e)
	{
		cerr << "Fatal error while reading \"" << db_filename << "\" [" << e.what() << "]" << endl;
		throw;
	}

	return (vmap);
}

char	BitcoinExchange::_parseDbSettings(std::string line)
{
	const char	*allowedSeparator = ",|";
	size_t		sep_pos = std::string::npos;

	for (int i = 0; i < 3 && sep_pos == std::string::npos; ++i)
		sep_pos = line.find(allowedSeparator[i]);
	if (sep_pos == std::string::npos)
		throw (std::invalid_argument("separator not found"));

	return (line.substr(sep_pos, 1).c_str()[0]);
}

float				BitcoinExchange::_computeValueAtTime(valuesMap::iterator &walletEntry, valuesMap &stockMarketPrices)
{
	float	valueAtTime = .0;

 	if (stockMarketPrices.count(walletEntry->first))
		valueAtTime = stockMarketPrices[walletEntry->first];
	else
	{
		valuesMap::iterator	nearestEntry = (std::upper_bound(
				stockMarketPrices.begin(),
				stockMarketPrices.end(),
				*walletEntry));

		if (nearestEntry != stockMarketPrices.begin())
			valueAtTime = (--nearestEntry)->second;
	}

	float	result = walletEntry->second * valueAtTime;

	return (result);
}

bool			BitcoinExchange::_isLeapYear(int year)
{
	return (year % 4 == 0 || year % 400 == 0);
}
