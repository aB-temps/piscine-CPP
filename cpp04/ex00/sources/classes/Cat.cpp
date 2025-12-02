/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 16:46:26 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
Cat::Cat(void): Animal()
{
	cout << "Cat of type: " << this->_type << " has been created!" << endl;
}

Cat::Cat(std::string type): Animal(type)
{
	cout << "Cat of type: " << type << " has been created!" << endl;
}

Cat::Cat(const Cat &copy): Animal(copy)
{
	cout << "Cat of type: " << this->_type << " has been created!(copy)" << endl;
}

Cat::~Cat(void)
{
	cout << "Cat of type: " << this->_type << " has been destructed!" << endl;
}

// Operator overloads ===================================================================
Cat		&Cat::operator=(const Cat &assign)
{
	if (this != &assign)
	{
		this->Animal::_type = assign.Animal::_type;
	}
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
std::string	Cat::getType(void)
{
	return (this->_type);
}

void		Cat::makeSound(void)
{
	cout << "Tchoutchoutchoutchou!" << endl;
}
