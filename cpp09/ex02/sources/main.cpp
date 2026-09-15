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
# include <sys/time.h>
# include <unistd.h>

# define DEQ 0
# define VEC 1

# define PARS 0
# define ALGO 1

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

	// - benchmark()
	// - time
	// - vector

		struct timeval	start; 
		struct timeval	now;
		uint32_t		chrono[2][2];


		gettimeofday(&start, NULL);
		deq = PmergeMe::buildCtn<std::deque<uint32_t> >(ac, av);
		gettimeofday(&now, NULL);

		chrono[DEQ][PARS] = (now.tv_usec - start.tv_usec) + ((now.tv_sec - start.tv_sec) * 1000000);
		cout	<< BOLD YELLOW "[DEQUE]\n" BLUE "- Parsed:" RST " " BOLD << deq
				<< RST DIM " [" << chrono[DEQ][PARS] << " us]\n" RST;

		gettimeofday(&start, NULL);
		PmergeMe::sort(deq);
		gettimeofday(&now, NULL);

		chrono[DEQ][ALGO] = (now.tv_usec - start.tv_usec) + ((now.tv_sec - start.tv_sec) * 1000000);
		cout	<< BOLD BLUE "- Sorted:" RST " " BOLD << deq
				<< RST DIM " [" << chrono[DEQ][ALGO] << " us]\n" BOLD GREEN "=> Total: " RST BOLD << chrono[DEQ][PARS] + chrono[DEQ][ALGO] << " us\n" RST;


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

	// PmergeMe.sort(vec);


	return (0);
}
