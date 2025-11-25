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

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
ClapTrap::ClapTrap(void):
	_name(DEFAULT_NAME),
	_hitPoints(DEFAULT_HP),
	_energyPoints(DEFAULT_EP),
	_attackDamages(DEFAULT_DAMAGE)
{
	cout << "Anonymous ClapTrap is born !" << endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hitPoints(DEFAULT_HP),
	_energyPoints(DEFAULT_EP),
	_attackDamages(DEFAULT_DAMAGE)
{
	cout << "ClapTrap " << this->_name << " is born !" << endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy):
	_name(copy._name),
	_hitPoints(copy._hitPoints),
	_energyPoints(copy._energyPoints),
	_attackDamages(copy._attackDamages)
{
	cout << "ClapTrap " << this->_name << " is born !(copy)" << endl;
}

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
	cout << "ClapTrap " << this->_name << " has been assigned !" << endl;
	return (*this);
}

// Member functions =====================================================================
void		ClapTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " is dead, it cannot attack." << endl;
		return;
	}
	cout 	<< "ClapTrap " << this->_name << " attacks "
			<< target << ", causing " << this->_attackDamages
			<< " points of damage !" << endl;
}

void		ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " is already dead, there is no need to attack a dead body." << endl;
		return;
	}
	this->_hitPoints -= amount;
	cout << "ClapTrap " << this->_name << " has been attacked(-" << amount << " hit points).";
	if (this->_hitPoints == 0)
		cout << " Causing its death.";
	cout << endl;
}

void		ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		cout << "ClapTrap " << this->_name << " is dead, it cannot repair itself." << endl;
		return;
	}
	if (this->_energyPoints < REPAIR_COST * amount)
	{
		cout	<< "Unfortunately, ClapTrap " << this->_name
				<< " has not enough energy points to restaure "
				<< amount << " hit points(" << this->_energyPoints << " energy points remaining)." << endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= amount * REPAIR_COST;
		cout	<< "ClapTrap " << this->_name
				<< " repaired itself(+" << amount << " hit points | -" 
				<< amount * REPAIR_COST << " energy points)." << endl;
	if (this->_energyPoints == 0)
		cout << "Warning: ClapTrap " << this->_name << " has no more energy points left." << endl;
	
}
