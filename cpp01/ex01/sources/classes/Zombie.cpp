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

# define BOLD	"\001\033[1m\002"
# define RED	"\001\033[31m\002"
# define GREEN	"\001\033[32m\002"
# define YELLOW	"\001\033[33m\002"
# define RST	"\001\033[0m\002"

using	std::endl;
using	std::cout;

Zombie::Zombie(void)
{
	this->_name = "Anonymous";
}

Zombie::~Zombie(void)
{
	cout << YELLOW "💀 " << BOLD << this->_name << RST YELLOW << " is dead." RST << endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

void	Zombie::announce(void) const
{
	cout << GREEN "🧟 " << BOLD << this->_name << RST GREEN << ": BraiiiiiiinnnzzzZ..." RST << endl;
}
