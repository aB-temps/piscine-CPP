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
AMateria::AMateria(void): IMateriaSource()
{
	this->_type = DEF_TYPENAME;
	cout << "AMateria of type:" << this->_type << ", has been constructed." << endl;
}

AMateria::AMateria(const AMateria &copy): IMateriaSource(copy)
{
	cout << "AMateria of type:" << this->_type << ", has been constructed(copy)." << endl;
}

AMateria::AMateria(std::string const &type): IMateriaSource()
{
	this->_type = type;
	cout << "AMateria of type:" << this->_type << ", has been constructed(type)." << endl;
}

AMateria::~AMateria(void)
{
	cout << "AMateria of type:" << this->_type << ", has been destructed." << endl;
}

// Operator overloads ===================================================================
AMateria			&AMateria::operator=(const AMateria &assign)
{
	if (this != &assign)
	{
		this->_type = assign._type;
	}
	cout << "AMateria(" << this->_type << "): assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
std::string const	AMateria::&getType(void) const
{
	return (this->_type);
}

void		AMateria::learnMateria(AMateria *m)
{

}

AMateria	*AMateria::createMateria(std::string const &type)
{

}

