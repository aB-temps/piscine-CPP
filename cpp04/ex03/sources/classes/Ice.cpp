/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 16:24:51 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
Ice::Ice(void): AMateria(ICE_TYPENAME) {}

Ice::Ice(const Ice &copy): AMateria(copy) {}

Ice::~Ice(void) {}

// Operator overloads ===================================================================
Ice		&Ice::operator=(const Ice &assign)
{
	if (this != &assign)
	{
		this->AMateria::operator=(assign);
	}
	return (*this);
}

// Member function ======================================================================

