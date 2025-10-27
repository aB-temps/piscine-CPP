/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:01:46 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/27 20:39:35 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

using	std::endl;
using	std::cout;

Zombie::Zombie(void)
{
	this->_name = "Anonymous";
}

Zombie::Zombie(std::string name)
{
	this->_name = name;
	cout << "Hello my name is: " << this->_name << endl;
}

Zombie::~Zombie(void)
{
	cout << this->_name << " is dead." << endl;
}

void	Zombie::announce(void) const
{
	cout << this->_name << ": BraiiiiiiinnnzzzZ..." << endl;
}
