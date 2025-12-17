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
	cout << "ICharacter interface has been instanciated." << endl;
}

ICharacter::ICharacter(const ICharacter &copy)
{
	cout << "ICharacter interface has been copied." << endl;
}

ICharacter::~ICharacter(void)
{
	cout << "ICharacter interface has been destructed." << endl;
}

// Operator overloads ===================================================================
ICharacter		&ICharacter::operator=(const ICharacter &assign)
{
	// if (this != &assign)
	// {
	// }
	cout << "ICharacter: assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================

