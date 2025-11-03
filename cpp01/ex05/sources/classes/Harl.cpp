/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 15:55:53 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/03 15:55:54 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Harl.hpp"

using	std::cout;
using	std::endl;

Harl::Harl(void)
{
	this->_features[DEBUG] = &Harl::_debug;
	this->_features[INFO] = &Harl::_info;
	this->_features[WARN] = &Harl::_warning;
	this->_features[ERROR] = &Harl::_error;

	this->_featureKeys[DEBUG] = "DEBUG";
	this->_featureKeys[INFO] = "INFO";
	this->_featureKeys[WARN] = "WARNING";
	this->_featureKeys[ERROR] = "ERROR";
}

void	Harl::complain(std::string level)
{
	int	i;

	i = 0;
	while (level != this->_featureKeys[i])
	{
		++i;
		if (i == FEATURE_QTY)
		{
			cout << "[ Probably complaining about insignificant problems ]" << endl;
			return;
		}
	}
	(this->*_features[i])();
}

void	Harl::_debug(void)
{
	cout 	<< "[ DEBUG ]\n"
			<< "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n"
	<< endl;
}

void	Harl::_info(void)
{
	cout	<< "[ INFO ]\n"
			<< "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
	<< endl;
}

void	Harl::_warning(void)
{
	cout 	<< "[ WARNING ]\n"
			<< "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.\n"
	<< endl;
}

void	Harl::_error(void)
{
	cout	<< "[ ERROR ]\n"
			<< "This is unacceptable! I want to speak to the manager now.\n"
	<< endl;
}
