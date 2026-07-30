/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:32:34 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/19 17:22:43 by abetemps         ###   ########.fr       */
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
			// bad arg
			cerr << "Usage: ./btc <file>" << endl;
			return (2);
		}

		for (int i = 1; i < ac; ++i)
		{
			cout << "For wallet \"" << av[i] << "\":\n";
			BitcoinExchange::displayWalletHistory(av[i]);
			cout << endl;
		}
	}
	catch (const std::invalid_argument &e)
	{
		cerr << "Error: could not open file \"" << e.what() << "\"." << endl;
		return (2);
	}
	catch (...)
	{
		return (1);
	}
	
	return (0);
}
