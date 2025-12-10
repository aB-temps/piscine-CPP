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
Cat::Cat(void): AAnimal("Cat"), _brain(new Brain()) {}

Cat::Cat(const Cat &copy): AAnimal(copy), _brain(new Brain(*copy._brain)) {}

Cat::~Cat(void)
{
	delete this->_brain;
}

// Operator overloads ===================================================================
Cat		&Cat::operator=(const Cat &assign)
{
	this->_type = assign._type;
	this->_brain = assign._brain;

	return (*this);
}

// Member function ======================================================================
void		Cat::makeSound(void) const
{
	cout << "Meowww!" << endl;
}
