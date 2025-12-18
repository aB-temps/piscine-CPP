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
#include "Ice.hpp"
#include "Cure.hpp"

using std::cout;
using std::endl;

// Constructors/Destructor ==============================================================
MateriaSource::MateriaSource(void)
{
	for (int i = 0; i <= KNOWLEDGE_SIZE; ++i)
	{
		this->_knowledge[i] = NULL;
	}

	// cout << "MateriaSource has been constructed." << endl;
}

MateriaSource::MateriaSource(const MateriaSource &copy)
{
	for (int i = 0; i <= KNOWLEDGE_SIZE; ++i)
	{
		this->_knowledge[i] = copy._knowledge[i];
	}
	// cout << "MateriaSource has been constructed(copy)." << endl;
}

MateriaSource::~MateriaSource(void)
{
	for (int i = 0; i < KNOWLEDGE_SIZE; ++i)
	{
		if (this->_knowledge[i])
			delete this->_knowledge[i];
	}
	// cout << "MateriaSource has been destructed." << endl;
}

// Operator overloads ===================================================================
MateriaSource &MateriaSource::operator=(const MateriaSource &assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < KNOWLEDGE_SIZE; ++i)
		{
			this->_knowledge[i] = assign._knowledge[i];
		}
	}
	// cout << "MateriaSource: assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
void MateriaSource::learnMateria(AMateria *m)
{
	int i = 0;

	if (!m)
	{
		cout << "Cannot learn non-existant Materia." << endl;
		return;
	}
	while (this->_knowledge[i])
	{
		if (this->_knowledge[i] == m)
		{
			cout << "Materia of type "
				<< m->getType() << ", has already been learned." << endl;
			return;
		}
		++i;
	}
	if (i == KNOWLEDGE_SIZE)
	{
		cout << "Unsufficent space to learn Materia of type "
			 << m->getType() << "." << endl;
		return;
	}
	this->_knowledge[i] = m;
	cout << "Materia of type "
		<< m->getType() << ", has been learned." << endl;
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
	for (int i = 0; i < KNOWLEDGE_SIZE && this->_knowledge[i]; ++i)
	{
		if (type == this->_knowledge[i]->getType())
		{
			cout << "Materia of type "
				<< type << ", has been created." << endl;
			return (this->_knowledge[i]->clone());
		}
	}
	cout << "No materia of type "
		<< type << ", has been learned yet." << endl;
	return (NULL);
}
