/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:28:09 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 15:51:44 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(void): _type(NULL) {}

Weapon::Weapon(std::string type): _type(type) {}

const std::string	&Weapon::getType(void) const
{
	return (const_cast<std::string&>(this->_type));
}

void				Weapon::setType(std::string type)
{
	this->_type = type;
}
