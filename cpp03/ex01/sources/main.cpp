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

#include	"ScavTrap.hpp"

using		std::cout;
using		std::endl;

int main(void)
{
	cout << "> Constructors" << endl;
	ScavTrap s1;
	ScavTrap s2("Johnny");
	ScavTrap s3(s2);
	ScavTrap s4;
	s4 = s1;
	cout << endl;

	cout << "> Stats display" << endl;
	s1.displayStats();
	cout << endl;
	s2.displayStats();
	cout << endl;
	s3.displayStats();
	cout << endl;

	s1.attack("Dark Vador");
	s1.takeDamage(5);
	s1.beRepaired(3);
	s1.displayStats();
	s1.beRepaired(11);
	s1.displayStats();
	cout << endl;

	s1.takeDamage(8);
	s1.displayStats();
	s1.attack("Dark Vador");
	cout << endl;

	s2.displayStats();
	s2.attack("David Guetta");
	s2.attack("David Guetta");
	s2.attack("David Guetta");
	s2.attack("David Guetta");
	s2.attack("David Guetta");
	s2.attack("David Guetta");
	s2.attack("David Guetta");
	s2.attack("David Guetta");
	s2.attack("David Guetta");
	s2.attack("David Guetta");
	s2.displayStats();
	s2.attack("David Guetta");
	cout << endl;

	s3.guardGate();
	s3.guardGate();

	cout << "> Destructors" << endl;
	return (0);
}
