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

#include	"DiamondTrap.hpp"

using		std::cout;
using		std::endl;

int main(void)
{
	cout << "> Constructors" << endl;
	ScavTrap s1;
	FragTrap f2("Johnny");
	DiamondTrap d3("Fred");
	DiamondTrap d4(d3);
	DiamondTrap d5;
	d5 = d3;
	cout << endl;

	cout << "> Stats display" << endl;
	s1.displayStats();
	cout << endl;
	f2.displayStats();
	cout << endl;
	d3.displayStats();
	cout << endl;
	d4.displayStats();
	cout << endl;
	d5.displayStats();
	cout << endl;

	d5.ScavTrap::attack("Zidane");
	cout << endl;

	d4.whoAmI();
	cout << endl;

	cout << "> Destructors" << endl;
	return (0);
}
