/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:13:53 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/27 19:23:04 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include "utils.hpp"

int	main(void)
{
	Zombie z1;
	Zombie z2("Guigui");

	randomChump("Kiki");	

	Zombie *z3;

	z3 = newZombie("Wedwhool");
	z3->announce();

	delete z3;
	return (0);
}
