/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 16:43:43 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

using std::cout;
using std::endl;

// Constructors/Destructor ==============================================================
Animal::Animal(void) : _type(DEF_TYPE)
{
	cout << "Animal of type: " << this->_type << " has been created!" << endl;
}

Animal::Animal(std::string type) : _type(type)
{
	cout << "Animal of type: " << type << " has been created!" << endl;
}

Animal::Animal(const Animal &copy) : _type(copy._type)
{
	cout << "Animal of type: " << this->_type << " has been created!(copy)" << endl;
}

Animal::~Animal(void)
{
	cout << "Animal of type: " << this->_type << " has been destructed!" << endl;
}

// Operator overloads ===================================================================
Animal &Animal::operator=(const Animal &assign)
{
	this->_type = assign._type;
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
const std::string &Animal::getType(void) const
{
	return (this->_type);
}

void Animal::makeSound(void) const
{
	cout << "Animal's sound!" << endl;
}
