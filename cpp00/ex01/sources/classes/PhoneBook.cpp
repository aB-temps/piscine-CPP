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
}

PhoneBook::~PhoneBook(void)
{
	//std::cout << "PhoneBook destructed..." << std::endl; 
}

void	PhoneBook::runFeature(e_Features feat)
{
	(this->*_features[feat])();
}

void	PhoneBook::_addContact(void)
{
	static int oldest_contact_index;

	if (this->_contact_quantity == MAX_CONTACTS)
	{
		std::cout << CLR_ERROR 
			<< "You have reached the contact limit." 
			<< RST << std::endl;
		if (ask_confirmation("Would you like to replace the oldest contact ?"))
		{
			this->_contacts[oldest_contact_index % 8].eraseContact();
			this->_contacts[oldest_contact_index++ % 8].createContact();
		}
	}
	else
	{
		this->_contacts[this->_contact_quantity].createContact();
		++this->_contact_quantity;

		}
}

void	PhoneBook::_displayContacts(void)
{
	std::cout << CLR_SCND << CORNER_TOP_LEFT;
	for (int i = 0; i < ((COL_WIDTH + 2) * 4) + 3; ++i)
		std::cout << FLOOR;
	std::cout << CORNER_TOP_RIGHT << RST << std::endl;
	for (int i = 0; i < this->_contact_quantity; ++i)
	{
		std::cout << CLR_SCND << WALL << " " << RST;
		this->_contacts[i].displayContactInformations(i + 1);
		std::cout << CLR_SCND << " " << WALL << std::endl;

	}	
	std::cout << CLR_SCND << CORNER_BOTTOM_LEFT;
	for (int i = 0; i < ((COL_WIDTH + 2) * 4) + 3; ++i)
		std::cout << FLOOR;
	std::cout << CORNER_BOTTOM_RIGHT << RST << std::endl;

}

void	PhoneBook::_searchContact(void)
{
	if (!this->_contact_quantity)
	{
		std::cout << CLR_WARN << "No contact registered.\n" << RST << std::endl;
		return;
	}
	this->_displayContacts();
	std::cout << this->_contact_quantity << "/" << MAX_CONTACTS << " contacts registered" << std::endl;
	
}
