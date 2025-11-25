/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 14:42:49 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/25 15:19:46 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"

// Constructors/Destructor ==============================================================
ClapTrap::ClapTrap(void):
	_name(DEFAULT_NAME),
	_hitPoints(DEFAULT_HP),
	_energyPoints(DEFAULT_EP),
	_attackDamages(DEFAULT_DAMAGE) {}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hitPoints(DEFAULT_HP),
	_energyPoints(DEFAULT_EP),
	_attackDamages(DEFAULT_DAMAGE) {}

ClapTrap::ClapTrap(const ClapTrap &copy):
	_name(copy._name),
	_hitPoints(copy._hitPoints),
	_energyPoints(copy._energyPoints),
	_attackDamages(copy._attackDamages) {}

ClapTrap::~ClapTrap(void) {}

// Operator overloads ===================================================================
ClapTrap	&ClapTrap::operator=(const ClapTrap &assign)
{
	if (this != &assign)
	{
		this->_name = assign._name;
		this->_hitPoints = assign._hitPoints;
		this->_energyPoints = assign._energyPoints;
		this->_attackDamages = assign._attackDamages;
	}
	return (*this);
}

// Member functions =====================================================================
void		ClapTrap::attack(const std::string &target)
{

}

void		ClapTrap::takeDamage(unsigned int amount)
{

}

void		ClapTrap::beRepaired(unsigned int amount)
{

}
