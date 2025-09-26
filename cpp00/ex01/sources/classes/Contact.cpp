/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:01:47 by abetemps          #+#    #+#             */
/*   Updated: 2025/09/26 03:26:08 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "Contact.hpp"

Contact::Contact(void)
{
	std::cout << "Contact created !" << std::endl; 
}

Contact::~Contact(void)
{
	std::cout << "Contact destructed..." << std::endl; 
}

bool Contact::createContact(void)
{
	std::cout << "Phone Number ?" << std::endl;
	std::cin >> this->_phoneNumber;
	std::cout << "First Name ?" << std::endl;
	std::cin >> this->_firstName;
	std::cout << "Last Name ?" << std::endl;
	std::cin >> this->_lastName;
	std::cout << "Nick Name ?" << std::endl;
	std::cin >> this->_nickName;
	std::cout << "Darkest Secret ?" << std::endl;
	std::cin >> this->_darkestSecret;
	return (true);
}

void Contact::displayContact(void)
{
	std::cout << this->_phoneNumber << std::endl;
	std::cout << this->_firstName << std::endl;
	std::cout <<  this->_lastName<< std::endl;
	std::cout << this->_nickName << std::endl;
	std::cout << this->_darkestSecret << std::endl;
}
