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

# include "RPN.hpp"

using	std::cout;
using	std::cerr;
using	std::endl;

int	main(int ac, char **av)
{
	if (ac < 2)
	{
		cerr << "Usage: ./RPN \"<inverted Polish mathematical expression>\" \"<...>\"" << endl;
		return (1);
	}

	for (int i = 1; i < ac; ++i)
	{
		cout	<< "Expression no " << i
				<< ": '" << av[i] << "'"
				<< endl;

		cout << "result: " << RPN::computeExpr(av[i]) << endl;
	}
	return (0);
}
