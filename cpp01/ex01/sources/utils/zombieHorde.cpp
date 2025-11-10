/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:01:46 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/27 21:10:49 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"

using	std::cout;
using	std::endl;

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zh;
	
	if (N < MIN_HORDE_SIZE)
	{
		cout	<< RED "Cannot build a Zombie Horde with less than "RST BOLD
				<< MIN_HORDE_SIZE << RST RED << " zombies." RST << endl;
		return (NULL);
	}

	try { zh = new Zombie[N]; }
	catch (const std::bad_alloc& error)
	{
		cout << RED "Allocation failed." RST << endl;
		return (NULL);
	}
	for (int i = 0; i < N; ++i)
		zh[i].setName(name);
	return (zh);
}
