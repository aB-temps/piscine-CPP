/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 16:24:51 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMateriaSource.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
IMateriaSource::IMateriaSource(void):
{
	cout << "IMateriaSource has been constructed." << endl;
}

IMateriaSource::IMateriaSource(const IMateriaSource &copy):
{
	cout << "IMateriaSource has been constructed(copy)." << endl;
}

IMateriaSource::~IMateriaSource(void)
{
	cout << "IMateriaSource has been destructed." << endl;
}

// Operator overloads ===================================================================
IMateriaSource		&IMateriaSource::operator=(const IMateriaSource &assign)
{
	cout << "IMateriaSource: assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
