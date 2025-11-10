/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:13:53 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/27 21:12:55 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

using	std::cout;
using	std::endl;

int	main(int ac, char *av[])
{
	Zombie		*zh;
	std::string	name;
	int			zombie_quantity;

	if (ac != 3)
	{
		name = DEFAULT_ZOMBIE_NAME;
		zombie_quantity = DEFAULT_HORDE_SIZE;
	}
	else
	{
		if (av[1][0] == '\0')
		{
			cout << RED "Zombie name cannot be empty."RST << endl;
			return (1);
		}
		name = av[1];
		zombie_quantity = 0;
		string_to_int(zombie_quantity, av[2]);
	}

	zh = zombieHorde(zombie_quantity, name);
	if (!zh)
		return (1);

	for (int i = 0; i < zombie_quantity; ++i)
		zh[i].announce();

	delete[] zh;
	return (0);
}
