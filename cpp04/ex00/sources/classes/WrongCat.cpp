/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 16:46:26 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
WrongCat::WrongCat(void): WrongAnimal("WrongCat") {}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy) {}

WrongCat::~WrongCat(void) {}

// Operator overloads ===================================================================
WrongCat		&WrongCat::operator=(const WrongCat &assign)
{
	this->_type = assign._type;
	return (*this);
}

// Member function ======================================================================
void		WrongCat::makeSound(void) const
{
	cout << "WrongMeowww!" << endl;
}
