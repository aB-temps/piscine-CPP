/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 14:51:43 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/27 17:27:29 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"DiamondTrap.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
DiamondTrap::DiamondTrap(void): ClapTrap(), ScavTrap(), FragTrap()
{
	this->_name = DT_DEF_NAME;
	this->ClapTrap::_name = (DT_DEF_NAME"_clap_name");
	this->_hitPoints = FT_DEF_HP;
	this->_energyPoints = ST_DEF_EP;
	this->_attackDamages = FT_DEF_DAMAGE;
	cout << "Anonymous DiamondTrap is born!" << endl;
}

DiamondTrap::DiamondTrap(std::string name): ClapTrap(name), ScavTrap(name), FragTrap(name)
{
	this->_name = name;
	this->ClapTrap::_name = name + "_clap_name";
	this->_hitPoints = FT_DEF_HP;
	this->_energyPoints = ST_DEF_EP;
	this->_attackDamages = FT_DEF_DAMAGE;
	cout << "DiamondTrap " << this->_name << " is born!" << endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &copy): ClapTrap(copy), ScavTrap(copy), FragTrap(copy)
{
	cout << "DiamondTrap " << this->_name << " is born!(copy)" << endl;
}

DiamondTrap::~DiamondTrap(void)
{
	cout << "DiamondTrap " << this->_name << " has been destructed!" << endl;
}

// Operator overloads ===================================================================
DiamondTrap	&DiamondTrap::operator=(const DiamondTrap &assign)
{
	ClapTrap::operator=(assign);
	ScavTrap::operator=(assign);
	FragTrap::operator=(assign);
	cout << "DiamondTrap " << this->_name << " has been assigned!" << endl;
	return (*this);
}

// Member functions =====================================================================
void		DiamondTrap::takeDamage(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		cout << "DiamondTrap " << this->DiamondTrap::_name << " is already dead, there is no need to attack a dead body." << endl;
		return;
	}
	this->_hitPoints = (this->_hitPoints >= amount ? this->_hitPoints - amount : 0);
	cout << "DiamondTrap " << this->_name << " has been attacked(-" << amount << " hit points).";
	if (this->_hitPoints == 0)
		cout << " Causing its death.";
	cout << endl;
}

void		DiamondTrap::beRepaired(unsigned int amount)
{
	if (this->_hitPoints == 0)
	{
		cout << "DiamondTrap " << this->_name << " is dead, it cannot repair itself." << endl;
		return;
	}
	if (this->_energyPoints < REPAIR_COST * amount)
	{
		cout	<< "Unfortunately, DiamondTrap " << this->_name
				<< " has not enough energy points to restaure "
				<< amount << " hit points(" << this->_energyPoints << " energy points remaining)." << endl;
		return;
	}
	this->_hitPoints += amount;
	this->_energyPoints -= amount * REPAIR_COST;
	cout	<< "DiamondTrap " << this->_name
			<< " repaired itself(+" << amount << " hit points)." << endl;
	if (this->_energyPoints == 0)
		cout << "Warning: DiamondTrap " << this->_name << " has no more energy points left." << endl;
	
}

void	DiamondTrap::whoAmI(void)
{
	cout	<< "DiamondTrap name is: " << this->_name 
			<< " and its ClapTrap name is " << this->ClapTrap::_name << endl;
}
