/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 16:24:51 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
MateriaSource::MateriaSource(void):
{
	cout << "MateriaSource has been constructed." << endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy):
{
	cout << "MateriaSource has been constructed(copy)." << endl;
}

MateriaSource::~MateriaSource(void)
{
	cout << "MateriaSource has been destructed." << endl;
}

// Operator overloads ===================================================================
MateriaSource		&MateriaSource::operator=(const MateriaSource &assign)
{
	// if (this != &assign)
	// {
	//
	// }
	cout << "MateriaSource: assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
void				AMateria::learnMateria(AMateria *m)
{

}

AMateria			*AMateria::createMateria(std::string const &type)
{

}
