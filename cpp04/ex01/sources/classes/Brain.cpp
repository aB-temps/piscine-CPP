/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/09 21:56:38 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
Brain::Brain(void)
{
	cout << "A brain has been created!" << endl;
}

Brain::Brain(const Brain &copy)
{
	for (int i = 0; i < 100; ++i)
		this->_ideas[i] = copy._ideas[i];
	cout << "A brain has been created!(copy)" << endl;
}

Brain::~Brain(void)
{
	cout << "A brain has been destructed, all its ideas are vanished..." << endl;
}

// Operator overloads ===================================================================
Brain		&Brain::operator=(const Brain &assign)
{
	if (this != &assign)
	{
		for (int i = 0; i < 100; ++i)
			this->_ideas[i] = assign._ideas[i];
	}
	cout << "Assignment operator called!" << endl;
	return (*this);
}

// Member function ======================================================================
