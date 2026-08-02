/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:32:34 by abetemps          #+#    #+#             */
/*   Updated: 2026/07/30 23:39:00 by abetemps         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

using	std::cout;
using	std::cerr;
using	std::endl;

int	main(int ac, char **av)
{
	try
	{
		if (ac < 2)
		{
			cerr << "Usage: ./btc <file>" << endl;
			return (2);
		}

		for (int i = 1; i < ac; ++i)
		{
			BitcoinExchange::displayWalletHistory(av[i]);
			cout << endl;
		}
	}
	catch (const std::invalid_argument &e)
	{
		return (2);
	}
	catch (const std::runtime_error &e)
	{
		return (1);
	}
	
	return (0);
}
