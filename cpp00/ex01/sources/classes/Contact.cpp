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

#include "Contact.hpp"

Contact::Contact(void)
{
	this->contact_infos_keys[PHONE] = "Phone Number";
	this->contact_infos_keys[FIRST_NAME] = "First Name";
	this->contact_infos_keys[LAST_NAME] = "Last Name";
	this->contact_infos_keys[NICK_NAME] = "Nick Name";
	this->contact_infos_keys[DARK_SECRET] = "Darkest Secret";
	//std::cout << "Contact created !" << std::endl; 
}

Contact::~Contact(void)
{
	// std::cout << "Contact destructed..." << std::endl; 
}

void Contact::createContact(void)
{
	int	i;

	std::cout << std::endl; 
	for (i = 0; i < CONTACT_INFOS_QUANTITY; ++i)
	{
		while (this->_contact_infos_values[i].empty() && !std::cin.eof())
		{
			std::cout << BOLD UNDL CLR_MAIN << this->contact_infos_keys[i] <<  " :" << RST << std::endl;
			std::getline(std::cin, this->_contact_infos_values[i]);
			std::cout << std::endl;
		}
	}
	std::cout << CLR_SUCCESS << "Contact " << BOLD CLR_MAIN
		<< this->_contact_infos_values[FIRST_NAME]
		<< " " << this->_contact_infos_values[LAST_NAME]
		<< CLR_SUCCESS << " has been successfully created !\n" << RST << std::endl;
}

void Contact::eraseContact(void)
{
	int	i;

	for (i = 0; i < CONTACT_INFOS_QUANTITY; ++i)
		this->_contact_infos_values[i].clear();
}

void Contact::displayContactInformations(int index)
{
	std::cout << std::setfill('_') << std::setw(COL_WIDTH);
	std::cout << index << " | ";
	for (int i = 1; i < 4; ++i)
	{
		if (this->_contact_infos_values[i].length() > COL_WIDTH)
		{
			std::cout << std::setfill('_') << std::right;
			std::cout << this->_contact_infos_values[i].substr(0, COL_WIDTH - 1) << ".";
		}
		else
		{
			std::cout << std::setfill('_') << std::right<< std::setw(COL_WIDTH);
			std::cout << this->_contact_infos_values[i];
		}
		if (i != 3)
			std::cout << " | ";
	}
}
