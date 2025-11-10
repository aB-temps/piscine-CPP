/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:28:06 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 10:35:39 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "HumanA.hpp"

using	std::cout;
using	std::endl;

HumanA::HumanA(std::string name, Weapon &weapon): _name(name), _weapon(weapon) {}

void	HumanA::attack(void) const
{
	cout 	<< this->_name
			<< " attacks with their weapon "
			<< this->_weapon.getType() << endl;
}
