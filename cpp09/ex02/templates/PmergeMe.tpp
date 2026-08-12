/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 19:30:04 by abetemps          #+#    #+#             */
/*   Updated: 2026/08/12 20:43:24 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <sstream>

template	<typename T>
T	PmergeMe::buildCtn(const int ac, char * const * av)
{
	T	container;

	for (int i = 1; i < ac; ++i)
	{
		if (!PmergeMe::_isOnlyNum(av[i]))
			throw std::invalid_argument(ERR BAD_ARG);
		std::stringstream	ss(av[i]);
		int64_t				number;
		while (ss >> number)
		{
			std::cout << number << std::endl;
			container.push_back(number);
		}
	}
	return (container);
}

