/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 16:24:51 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
AMateria::AMateria(void):
{
}

AMateria::AMateria(const AMateria &copy):
{
}

AMateria::~AMateria(void)
{
}

// Operator overloads ===================================================================
AMateria		&AMateria::operator=(const AMateria &assign)
{
	if (this != &assign)
	{
	}
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================

