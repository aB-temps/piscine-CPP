/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 16:43:43 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
AAnimal::AAnimal(void): _type(DEF_ATYPE)
{
	cout << "AAnimal of type: " << this->_type << " has been created!" << endl;
}

AAnimal::AAnimal(std::string type): _type(type)
{
	cout << "AAnimal of type: " << type << " has been created!" << endl;
}

AAnimal::AAnimal(const AAnimal &copy): _type(copy._type)
{
	cout << "AAnimal of type: " << this->_type << " has been created!(copy)" << endl;
}

AAnimal::~AAnimal(void)
{
	cout << "AAnimal of type: " << this->_type << " has been destructed!" << endl;
}

// Operator overloads ===================================================================
AAnimal		&AAnimal::operator=(const AAnimal &assign)
{
	if (this != &assign)
	{
		this->_type = assign._type;
	}
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
const std::string	&AAnimal::getType(void) const
{
	return (this->_type);
}
