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

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name)
{
	Zombie	*zh;

	zh = new Zombie[N];


	for (int i = 0; i < N; ++i)
	{
		zh[i] = Zombie(name);
	}

	return (zh);
}
