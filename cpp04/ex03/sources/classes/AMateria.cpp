/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 16:24:51 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
AMateria::AMateria(void): _type(DEF_TYPENAME), _learned(false)
{
	// cout << "AMateria of type:" << this->_type << " has been constructed." << endl;
}

AMateria::AMateria(const AMateria &copy): _type(copy._type), _learned(copy._learned)
{
	// cout << "AMateria of type:" << this->_type << " has been constructed(copy)." << endl;
}

AMateria::AMateria(std::string const &type): _type(type), _learned(false)
{
	// cout << "AMateria of type:" << this->_type << " has been constructed(type)." << endl;
}

AMateria::~AMateria(void)
{
	// cout << "AMateria of type:" << this->_type << " has been destructed." << endl;
}

// Operator overloads ===================================================================
AMateria			&AMateria::operator=(const AMateria &assign)
{
	this->_learned = assign._learned;
	if (this->_type != assign.getType())
		cout << "Cannot assign AMaterias of different types." << endl;
	// cout << "AMateria(" << this->_type << "): assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
std::string const	&AMateria::getType(void) const
{
	return (this->_type);
}

bool const			&AMateria::getLearnedState(void) const
{
	return (this->_learned);
}

void				AMateria::setLearnedState(const bool &state)
{
	this->_learned = state;
}

void				AMateria::use(ICharacter &target)
{
	cout << "Using Materia on " << target.getName() << "." << endl;
}
