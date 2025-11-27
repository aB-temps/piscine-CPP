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

#include	"ClapTrap.hpp"

using		std::cout;
using		std::endl;

int main(void)
{
	cout << "> Constructors" << endl;
	ClapTrap c1;
	ClapTrap c2("Fred");
	ClapTrap c3(c2);
	ClapTrap c4;

	c4 = c1;
	cout << endl;

	cout << "> Stats display" << endl;
	c1.displayStats();
	cout << endl;
	c2.displayStats();
	cout << endl;
	c3.displayStats();
	cout << endl;

	c1.attack("Dark Vador");
	c1.takeDamage(5);
	c1.beRepaired(3);
	c1.displayStats();
	c1.beRepaired(11);
	c1.displayStats();
	cout << endl;

	c1.takeDamage(8);
	c1.displayStats();
	c1.attack("Dark Vador");
	cout << endl;

	c2.displayStats();
	c2.attack("David Guetta");
	c2.attack("David Guetta");
	c2.attack("David Guetta");
	c2.attack("David Guetta");
	c2.attack("David Guetta");
	c2.attack("David Guetta");
	c2.attack("David Guetta");
	c2.attack("David Guetta");
	c2.attack("David Guetta");
	c2.attack("David Guetta");
	c2.displayStats();
	c2.attack("David Guetta");
	cout << endl;

	cout << "> Destructors" << endl;
	return (0);
}
