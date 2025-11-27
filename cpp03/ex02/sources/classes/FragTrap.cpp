/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:51:43 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/27 16:50:48 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"FragTrap.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
FragTrap::FragTrap(void): ClapTrap()
{
	this->_hitPoints = FT_DEF_HP;
	this->_energyPoints = FT_DEF_EP;
	this->_attackDamages = FT_DEF_DAMAGE;
	cout << "Anonymous FragTrap is born!" << endl;
}

FragTrap::FragTrap(std::string name): ClapTrap(name)
{
	this->_hitPoints = FT_DEF_HP;
	this->_energyPoints = FT_DEF_EP;
	this->_attackDamages = FT_DEF_DAMAGE;
	cout << "FragTrap " << this->_name << " is born!" << endl;
}

FragTrap::FragTrap(const FragTrap &copy): ClapTrap(copy)
{
	cout << "FragTrap " << this->_name << " is born!(copy)" << endl;
}

FragTrap::~FragTrap(void)
{
	cout << "FragTrap " << this->_name << " has been destructed!" << endl;
}

// Operator overloads ===================================================================
FragTrap	&FragTrap::operator=(const FragTrap &assign)
{
	ClapTrap::operator=(assign);
	cout << "FragTrap " << this->_name << " has been assigned!" << endl;
	return (*this);
}

// Member functions =====================================================================
void		FragTrap::attack(const std::string &target)
{
	if (this->_hitPoints == 0)
	{
		cout << "FragTrap " << this->_name << " is dead, it cannot attack." << endl;
		return;
	}
	if (this->_energyPoints < ATTACK_COST)
	{
		cout	<< "Unfortunately, FragTrap " << this->_name
				<< " has not enough energy points to attack "
				<< target << "(" << this->_energyPoints << " energy points remaining)." << endl;
		return;
	}
	this->_energyPoints -= ATTACK_COST;
	cout 	<< "FragTrap " << this->_name << " attacks "
			<< target << ", causing " << this->_attackDamages
			<< " points of damage!" << endl;
}

void		FragTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		cout << "FragTrap " << this->_name << " is already dead, there is no need to attack a dead body." << endl;
		return;
	}
	this->_hitPoints = (this->_hitPoints >= amount ? this->_hitPoints - amount : 0);
	cout << "FragTrap " << this->_name << " has been attacked(-" << amount << " hit points).";
	if (this->_hitPoints == 0)
		cout << " Causing its death.";
	cout << endl;
}

void		FragTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		cout << "FragTrap " << this->_name << " is dead, it cannot repair itself." << endl;
		return;
	}
	if (this->_energyPoints < REPAIR_COST * amount)
	{
		cout	<< "Unfortunately, FragTrap " << this->_name
				<< " has not enough energy points to restaure "
				<< amount << " hit points(" << this->_energyPoints << " energy points remaining)." << endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= amount * REPAIR_COST;
	cout	<< "FragTrap " << this->_name
			<< " repaired itself(+" << amount << " hit points)." << endl;
	if (this->_energyPoints == 0)
		cout << "Warning: FragTrap " << this->_name << " has no more energy points left." << endl;
	
}

void	FragTrap::highFivesGuys(void)
{
	cout	<< "FragTrap " << this->_name
			<< " is high-fiving all its homies." << endl;
}
