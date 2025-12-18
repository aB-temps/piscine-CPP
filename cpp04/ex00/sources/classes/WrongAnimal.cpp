/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/09 19:24:56 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

using std::cout;
using std::endl;

// Constructors/Destructor ==============================================================
WrongAnimal::WrongAnimal(void) : _type(DEF_WTYPE)
{
	cout << "WrongAnimal of type: " << this->_type << " has been created!" << endl;
}

WrongAnimal::WrongAnimal(std::string type) : _type(type)
{
	cout << "WrongAnimal of type: " << type << " has been created!" << endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : _type(copy._type)
{
	cout << "WrongAnimal of type: " << this->_type << " has been created!(copy)" << endl;
}

WrongAnimal::~WrongAnimal(void)
{
	cout << "WrongAnimal of type: " << this->_type << " has been destructed!" << endl;
}

// Operator overloads ===================================================================
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &assign)
{
	this->_type = assign._type;
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
const std::string &WrongAnimal::getType(void) const
{
	return (this->_type);
}

void WrongAnimal::makeSound(void) const
{
	cout << "WrongAnimal's sound!" << endl;
}
