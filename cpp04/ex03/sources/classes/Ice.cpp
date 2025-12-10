/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 16:24:51 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
Cure::Cure(void):
{
}

Cure::Cure(const Cure &copy):
{
}

Cure::~Cure(void)
{
}

// Operator overloads ===================================================================
Cure		&Cure::operator=(const Cure &assign)
{
	if (this != &assign)
	{
	}
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================

