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
Dog::Dog(void): Animal("Dog") {}

Dog::Dog(const Dog &copy): Animal(copy) {}

Dog::~Dog(void) {}

// Operator overloads ===================================================================
Dog		&Dog::operator=(const Dog &assign)
{
	this->Animal::_type = assign.Animal::_type;
	return (*this);
}

// Member function ======================================================================
void		Dog::makeSound(void) const
{
	cout << "Ouafffff!" << endl;
}
