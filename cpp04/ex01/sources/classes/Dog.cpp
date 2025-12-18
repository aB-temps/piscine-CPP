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
Dog::Dog(void): Animal("Dog"), _brain(new Brain()) {}

Dog::Dog(const Dog &copy): Animal(copy), _brain(new Brain(*copy._brain)) {}

Dog::~Dog(void)
{
	delete this->_brain;
}

// Operator overloads ===================================================================
Dog		&Dog::operator=(const Dog &assign)
{
	if (this != &assign)
	{
		this->_type = assign._type;
		delete this->_brain;
		this->_brain = new Brain(*assign._brain);
	}
	return (*this);
}

// Member function ======================================================================
void		Dog::makeSound(void) const
{
	cout << "Ouafffff!" << endl;
}
