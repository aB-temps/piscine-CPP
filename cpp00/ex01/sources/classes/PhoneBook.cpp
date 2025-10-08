/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:01:47 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/07 23:10:27 by abetemps         ###   ########.fr       */
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
		std::cout << "Too many contacts..." << std::endl;
	else
	{
		this->_contacts[this->_contact_quantity].createContact();
		this->_contact_quantity++;
	}
}

void	PhoneBook::_displayContacts(void)
{
	std::cout << CORNER_TOP_LEFT;
	for (int i = 0; i < ((COL_WIDTH + 2) * 4) + 3; ++i)
		std::cout << FLOOR;
	std::cout << CORNER_TOP_RIGHT << std::endl;
	for (int i = 0; i < this->_contact_quantity; ++i)
	{
		std::cout << WALL << " ";
		this->_contacts[i].displayContactInformations(i + 1);
		std::cout << " " << WALL << std::endl;

	}	
	std::cout << CORNER_BOTTOM_LEFT;
	for (int i = 0; i < ((COL_WIDTH + 2) * 4) + 3; ++i)
		std::cout << FLOOR;
	std::cout << CORNER_BOTTOM_RIGHT << std::endl;

}

void	PhoneBook::_searchContact(void)
{
	std::cout << "SearchContact" << std::endl;
	this->_displayContacts();
	std::cout << this->_contact_quantity << " contacts registered" << std::endl;
}

void	PhoneBook::_exitPhoneBook(void)
{
	std::string input;
	std::cout << RED << "If you exit, your contacts will be lost forever. Confirm [Y/N]" << RST << std::endl;
	while (input.empty() && !std::cin.eof())
	{
		if (input == "Y" || input == "y")
			std::cout << "ExitPhoneBook" << std::endl;
		else if (input == "N" || input == "n")
			return ((void *)0);			
	}
	return ((void *)1);
}
