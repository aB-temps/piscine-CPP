/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:01:47 by abetemps          #+#    #+#             */
/*   Updated: 2025/09/28 01:52:25 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void)
{
	this->_contact_quantity = 0;
	this->_features[ADD] = &PhoneBook::_addContact;
	this->_features[SEARCH] = &PhoneBook::_searchContact;
	this->_features[EXIT] = &PhoneBook::_exitPhoneBook;
	std::cout << "PhoneBook created !" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructed..." << std::endl; 
}

void	PhoneBook::runFeature(e_Features feat)
{
	(this->*_features[feat])();
}

void	PhoneBook::_addContact(void)
{
	if (this->_contact_quantity == MAX_CONTACTS)
		std::cout << "To many contacts..." << std::endl;
	else
	{
		this->_contacts[this->_contact_quantity].createContact();
		this->_contact_quantity++;
		std::cout << "AddContact" << std::endl;
	}
}

void	PhoneBook::_displayContacts(void)
{
	for (int i = 0; i < this->_contact_quantity; ++i)
	{
		std::cout << "Contact no " << i + 1 << std::endl;
		this->_contacts[i].displayContactInformations();
		std::cout << std::endl;
	}
}

void	PhoneBook::_searchContact(void)
{
	std::cout << "SearchContact" << std::endl;
	this->_displayContacts();
	std::cout << this->_contact_quantity << " contacts registered" << std::endl;
}

void	PhoneBook::_exitPhoneBook(void)
{
	std::cout << "ExitPhoneBook" << std::endl;
}
