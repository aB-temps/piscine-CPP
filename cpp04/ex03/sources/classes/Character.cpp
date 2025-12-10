/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 17:36:36 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
Character::Character(void):
{
}

Character::Character(const Character &copy):
{
}

Character::~Character(void)
{
}

// Operator overloads ===================================================================
Character		&Character::operator=(const Character &assign)
{
	if (this != &assign)
	{
	}
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================

