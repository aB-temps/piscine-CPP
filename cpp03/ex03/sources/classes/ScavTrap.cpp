/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:51:43 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/27 16:41:58 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"ScavTrap.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
ScavTrap::ScavTrap(void): ClapTrap(), _gateKeeperMode(false)
{
	this->_hitPoints = ST_DEF_HP;
	this->_energyPoints = ST_DEF_EP;
	this->_attackDamages = ST_DEF_DAMAGE;
	cout << "Anonymous ScavTrap is born!" << endl;
}

ScavTrap::ScavTrap(std::string name): ClapTrap(name), _gateKeeperMode(false)
{
	this->_hitPoints = ST_DEF_HP;
	this->_energyPoints = ST_DEF_EP;
	this->_attackDamages = ST_DEF_DAMAGE;
	cout << "ScavTrap " << this->_name << " is born!" << endl;
}

ScavTrap::ScavTrap(const ScavTrap &copy): ClapTrap(copy), _gateKeeperMode(copy._gateKeeperMode)
{
	cout << "ScavTrap " << this->_name << " is born!(copy)" << endl;
}

ScavTrap::~ScavTrap(void)
{
	cout << "ScavTrap " << this->_name << " has been destructed!" << endl;
}

// Operator overloads ===================================================================
ScavTrap	&ScavTrap::operator=(const ScavTrap &assign)
{
	if (this != &assign)
	{
		ClapTrap::operator=(assign);
		this->_gateKeeperMode = assign._gateKeeperMode;
	}
	cout << "ScavTrap " << this->_name << " has been assigned!" << endl;
	return (*this);
}

// Member functions =====================================================================
void		ScavTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		cout << "ScavTrap " << this->_name << " is dead, it cannot attack." << endl;
		return;
	}
	if (this->_energyPoints < ATTACK_COST)
	{
		cout	<< "Unfortunately, ScavTrap " << this->_name
				<< " has not enough energy points to attack "
				<< target << "(" << this->_energyPoints << " energy points remaining)." << endl;
		return;
	}
	this->_energyPoints -= ATTACK_COST;
	cout 	<< "ScavTrap " << this->_name << " attacks "
			<< target << ", causing " << this->_attackDamages
			<< " points of damage!" << endl;
}

void		ScavTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		cout << "ScavTrap " << this->_name << " is already dead, there is no need to attack a dead body." << endl;
		return;
	}
	this->_hitPoints = (this->_hitPoints >= amount ? this->_hitPoints - amount : 0);
	cout << "ScavTrap " << this->_name << " has been attacked(-" << amount << " hit points).";
	if (this->_hitPoints == 0)
		cout << " Causing its death.";
	cout << endl;
}

void		ScavTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		cout << "ScavTrap " << this->_name << " is dead, it cannot repair itself." << endl;
		return;
	}
	if (this->_energyPoints < REPAIR_COST * amount)
	{
		cout	<< "Unfortunately, ScavTrap " << this->_name
				<< " has not enough energy points to restaure "
				<< amount << " hit points(" << this->_energyPoints << " energy points remaining)." << endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= amount * REPAIR_COST;
	cout	<< "ScavTrap " << this->_name
			<< " repaired itself(+" << amount << " hit points)." << endl;
	if (this->_energyPoints == 0)
		cout << "Warning: ScavTrap " << this->_name << " has no more energy points left." << endl;
	
}

void	ScavTrap::displayStats(void)
{
	cout	<< "[STATS] ScavTrap \"" << this->_name << "\":\n"
			<< "gateKeeperMode: " << (this->_gateKeeperMode ? "true" : "false") << "\n"
			<< "hitPoints: " << this->_hitPoints << "\n"
			<< "energyPoints: " << this->_energyPoints << "\n"
			<< "attackDamages: " << this->_attackDamages << endl;

}

void	ScavTrap::guardGate(void)
{
	cout	<< "ScavTrap " << this->_name
		<< (this->_gateKeeperMode ? " has already activated " : " activated ")
		<< "gate keeper mode!" << endl;
	this->_gateKeeperMode = true;
}
