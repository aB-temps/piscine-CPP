/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/21 17:03:33 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

using	std::cout;
using	std::cerr;
using	std::endl;

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		cerr << ERR << BAD_ARG_QTY "\n" << USAGE << endl;
		return (2);
	}

	std::deque<uint32_t>	deq;
	std::vector<uint32_t>	vec;

	try
	{
		deq = PmergeMe::buildCtn<std::deque<uint32_t> >(ac, av);
		vec = PmergeMe::buildCtn<std::vector<uint32_t> >(ac, av);
	}
	catch (const std::invalid_argument &e)
	{
		cerr << e.what() << endl;
		return (2);
	}
	catch (const std::exception &e)
	{
		cerr << e.what() << endl;
		return (1);
	}

	// TODO: 
	// - time
	// - style

	cout << "[Before]\nDeque: " << deq << "\nVector: " << vec << endl;

	PmergeMe::sort(deq);
	// PmergeMe.sort(vec);

	cout << "\n[AFTER]\nDeque: " << deq << "\nVector: " << vec << endl;

	return (0);
}
