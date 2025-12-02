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

#include	"FragTrap.hpp"

using		std::cout;
using		std::endl;

int main(void)
{
	cout << "> Constructors" << endl;
	FragTrap *f1 = new FragTrap;
	FragTrap f2("Johnny");
	FragTrap f3(f2);
	FragTrap f4;
	f4 = *f1;
	cout << endl;

	cout << "> Stats display" << endl;
	f1->displayStats();
	cout << endl;
	f2.displayStats();
	cout << endl;
	f3.displayStats();
	cout << endl;
	f4.displayStats();
	cout << endl;

	f1->attack("Dark Vador");
	f1->takeDamage(50);
	f1->beRepaired(30);
	f1->displayStats();
	f1->beRepaired(110);
	f1->displayStats();
	cout << endl;

	f1->takeDamage(80);
	f1->displayStats();
	f1->attack("Dark Vador");
	cout << endl;

	f2.displayStats();
	f2.attack("David Guetta");
	f2.attack("David Guetta");
	f2.attack("David Guetta");
	f2.attack("David Guetta");
	f2.attack("David Guetta");
	f2.attack("David Guetta");
	f2.attack("David Guetta");
	f2.attack("David Guetta");
	f2.attack("David Guetta");
	f2.attack("David Guetta");
	f2.displayStats();
	f2.attack("David Guetta");
	cout << endl;

	f3.highFivesGuys();
	cout << endl;

	cout << "> Destructors" << endl;
	delete f1;
	return (0);
}
