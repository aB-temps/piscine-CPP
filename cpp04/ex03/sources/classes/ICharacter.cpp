/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 16:24:51 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ICharacter.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
ICharacter::ICharacter(void):
{
}

ICharacter::ICharacter(const ICharacter &copy):
{
}

ICharacter::~ICharacter(void)
{
}

// Operator overloads ===================================================================
ICharacter		&ICharacter::operator=(const ICharacter &assign)
{
	if (this != &assign)
	{
	}
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================

