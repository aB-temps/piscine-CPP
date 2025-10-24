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

#include <sstream>
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
			this->_contacts[oldest_contact_index].eraseContact();
			this->_contacts[oldest_contact_index++].createContact(); // oldest_contact_index peut overflow zebi
			oldest_contact_index %= MAX_CONTACTS;
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
	std::cout << CLR_ALT << CORNER_TOP_LEFT;
	for (int i = 0; i < ((COL_WIDTH + 2) * 4) + 3; ++i)
		std::cout << FLOOR;
	std::cout << CORNER_TOP_RIGHT << RST << std::endl;
	for (int i = 0; i < this->_contact_quantity; ++i)
	{
		std::cout << CLR_ALT << WALL << " " << RST;
		this->_contacts[i].displayContactShort(i + 1);
		std::cout << CLR_ALT << " " << WALL << std::endl;

	}	
	std::cout << CLR_ALT << CORNER_BOTTOM_LEFT;
	for (int i = 0; i < ((COL_WIDTH + 2) * 4) + 3; ++i)
		std::cout << FLOOR;
	std::cout << CORNER_BOTTOM_RIGHT << RST << std::endl;
}

void	PhoneBook::_searchContact(void)
{
	std::string			input;
	std::stringstream	ss_input;
	int					index;

	if (!this->_contact_quantity)
	{
		std::cout << CLR_WARN << "No contact registered.\n" << RST << std::endl;
		return;
	}
	this->_displayContacts();
	std::cout << BOLD CLR_MAIN << this->_contact_quantity << RST << "/" << MAX_CONTACTS << " contacts registered\n" << std::endl;
	while (!std::cin.eof())
	{
		std::cout << CLR_SCND << "Enter a " << BOLD << "contact index" << RST CLR_SCND
			<< " to see full informations or " << BOLD << "HOME" << RST CLR_SCND
			<< " to go back to main menu." << RST << std::endl;
		std::getline(std::cin, input);
		if (!input.empty() && str_is(input, isdigit))
		{
			ss_input << input;
			ss_input >> index;
			if (index >= 1 && index <= this->_contact_quantity)
				this->_contacts[index - 1].displayContactFull();
			else if (index > 0 && ask_confirmation("Not in range. Would you like to add a new contact ?"))
				this->_addContact();
		}
		else if (input == "HOME")
		{
			input.clear();
			return;
		}
		else if (!input.empty())
			std::cout << CLR_ERROR << "Invalid command.\n" << RST << std::endl;
		input.clear();
		ss_input.clear();
	}

}
