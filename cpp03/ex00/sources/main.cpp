/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 11:14:22 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap c1;
	ClapTrap c2("Fred");
	ClapTrap c3(c2);


	c1.takeDamage(9);
	c1.beRepaired(9);

	c2.takeDamage(10);
	c2.takeDamage(10);
	c2.beRepaired(10);
	c2.attack("John");
	c1.takeDamage(10);

	return (0);
}
