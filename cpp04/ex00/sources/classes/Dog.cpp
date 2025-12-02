/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 16:46:34 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
Dog::Dog(void): Animal()
{
	cout << "Dog of type: " << this->_type << " has been created!" << endl;
}

Dog::Dog(std::string type): Animal(type)
{
	cout << "Dog of type: " << type << " has been created!" << endl;
}

Dog::Dog(const Dog &copy): Animal(copy)
{
	cout << "Dog of type: " << this->_type << " has been created!(copy)" << endl;
}

Dog::~Dog(void)
{
	cout << "Dog of type: " << this->_type << " has been destructed!" << endl;
}

// Operator overloads ===================================================================
Dog		&Dog::operator=(const Dog &assign)
{
	if (this != &assign)
	{
		this->_type = assign._type;
	}
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
std::string	Dog::getType(void)
{
	return (this->_type);
}

void		Dog::makeSound(void)
{
	cout << "Tchoutchoutchoutchou!" << endl;
}
