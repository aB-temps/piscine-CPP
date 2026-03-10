/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/10 13:20:00 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
Data::Data(void): _name("Default") {}

Data::Data(const std::string &name): _name(name) {}

Data::Data(const Data &copy): _name(copy._name) {}

Data::~Data(void) {}

// Operator overloads ===================================================================
Data		&Data::operator=(const Data &assign)
{
	if (this != &assign)
		this->_name = assign._name;
	return (*this);
}

// Member function ======================================================================
const std::string	&Data::getName(void) const
{
	return (this->_name);
}
