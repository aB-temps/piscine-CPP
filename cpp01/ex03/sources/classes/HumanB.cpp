/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:28:05 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 10:35:48 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanB.hpp"

using	std::cout;
using	std::endl;

HumanB::HumanB(std::string name): _name(name), _weapon(NULL) {}

void	HumanB::setWeapon(Weapon *weapon)
{
	this->_weapon = weapon;
}

void	HumanB::attack(void) const
{
	if (!this->_weapon)
	{
		cout << this->_name << " is disarmed." << endl;
		return;
	}

	cout 	<< this->_name
			<< " attacks with their weapon "
			<< this->_weapon->getType() << endl;
}
