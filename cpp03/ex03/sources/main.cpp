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
	ClapTrap *c1 = new ClapTrap("Clappie");
	c1->displayStats();
	cout << endl;

	ScavTrap *s1 = new ScavTrap("Scavie");
	s1->guardGate();
	s1->displayStats();
	cout << endl;

	FragTrap *f1 = new FragTrap("Fragie");
	f1->displayStats();
	cout << endl;

	DiamondTrap *d1 = new DiamondTrap("Diamsou");
	d1->displayStats();
	cout << endl;

	d1->ScavTrap::attack("Zidane");
	d1->whoAmI();
	cout << endl;


	cout << "> Destructors" << endl;
	delete c1;
	cout << endl;
	delete s1;
	cout << endl;
	delete f1;
	cout << endl;
	delete d1;
	cout << endl;

	return (0);
}
