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
Cat::Cat(void): Animal("Cat") {}

Cat::Cat(const Cat &copy): Animal(copy) {}

Cat::~Cat(void) {}

// Operator overloads ===================================================================
Cat		&Cat::operator=(const Cat &assign)
{
	this->Animal::_type = assign.Animal::_type;
	return (*this);
}

// Member function ======================================================================
void		Cat::makeSound(void) const
{
	cout << "Meowww!" << endl;
}
