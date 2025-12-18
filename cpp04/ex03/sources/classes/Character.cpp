/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 17:36:36 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"Character.hpp"

using 		std::cout;
using		std::endl;

AMateria	**Character::_ground = NULL;
int			Character::_ground_quantity = 0;

// Constructors/Destructor ==============================================================
Character::Character(void) : _name(DEF_CHARNAME)
{
	for (int i = 0; i <= INV_SIZE; ++i)
		this->_inventory[i] = NULL;
	// cout << "Character " << this->_name << "is born." << endl;
}

Character::Character(std::string name) : _name(name)
{
	for (int i = 0; i <= INV_SIZE; ++i)
		this->_inventory[i] = NULL;
	// cout << "Character " << this->_name << "is born." << endl;
}

Character::Character(const Character &copy) : ICharacter(copy), _name(copy._name)
{
	for (int i = 0; i < INV_SIZE; ++i)
		this->_inventory[i] = copy._inventory[i]->clone();
	// cout << "Character " << this->_name << "is born.(copy)" << endl;
}

Character::~Character(void)
{
	for (int i = 0; i < INV_SIZE; ++i)
	{
		if (this->_inventory[i])
			delete this->_inventory[i];
	}
	// cout << "Character " << this->_name << "has been destructed." << endl;
}

// Operator overloads ===================================================================
Character 			&Character::operator=(const Character &assign)
{
	if (this != &assign)
	{
		this->_name = assign._name;
		for (int i = 0; i < INV_SIZE; ++i)
		{
			if (this->_inventory[i])
				delete this->_inventory[i];
			this->_inventory[i] = assign._inventory[i]->clone();
		}
	}
	// cout << "Character: assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
int					&Character::getGroundQty(void)
{
	return (_ground_quantity);
}

void				Character::clearGround(void)
{
	if (!_ground)
	{
		cout << "Nothing to clear on the ground." << endl;
		return;
	}
	for (int i = 0; i < _ground_quantity; ++i)
	{
		delete _ground[i];
	}
	delete[] _ground;
	cout << "Ground has been cleared!" << endl;
}

std::string const	&Character::getName(void) const
{
	return (this->_name);
}

void 				Character::equip(AMateria *m)
{
	int i = 0;

	if (!m)
	{
		cout << "Cannot equip non-existant Materia." << endl;
		return;
	}
	while (this->_inventory[i])
		++i;
	if (i == INV_SIZE)
	{
		cout << "Unsufficent space in inventory to store Materia of type "
			 << m->getType() << "." << endl;
		return;
	}
	this->_inventory[i] = m;
}

void				Character::unequip(int idx)
{
	if (idx >= INV_SIZE)
	{
		cout << "Index " << idx
			 << " is out of inventory("
			 << INV_SIZE << ")." << endl;
		return;
	}
	else if (!this->_inventory[idx])
	{
		cout << "Cannot unequip non-existant Materia("
			 << idx << ")." << endl;
		return;
	}
	cout << "Materia of type " << this->_inventory[idx]->getType()
		 << " has been unequiped." << endl;



	AMateria **tmp = _ground;
	_ground = new AMateria*[_ground_quantity + 1];
	_ground[_ground_quantity] = this->_inventory[idx];
	for (int i = 0; i < _ground_quantity; ++i)
		_ground[i] = tmp[i];
	++_ground_quantity;

	this->_inventory[idx] = NULL;
}

void 				Character::use(int idx, ICharacter &target)
{
	if (!this->_inventory[idx])
	{
		cout << "Cannot use non-existant Materia("
			 << idx << ")." << endl;
		return;
	}
	this->_inventory[idx]->use(target);
}
