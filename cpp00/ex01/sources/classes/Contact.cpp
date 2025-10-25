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

using	std::cin;
using	std::cout;
using	std::endl;

Contact::Contact(void)
{
	this->contact_infos_keys[PHONE] = "Phone Number";
	this->contact_infos_keys[FIRST_NAME] = "First Name";
	this->contact_infos_keys[LAST_NAME] = "Last Name";
	this->contact_infos_keys[NICK_NAME] = "Nick Name";
	this->contact_infos_keys[DARK_SECRET] = "Darkest Secret";
}

void Contact::createContact(void)
{
	std::string input;
	int	i;

	cout << endl; 
	for (i = 0; i < CONTACT_INFOS_QUANTITY; ++i)
	{
		while (this->_contact_infos_values[i].empty())
		{
			cout << BOLD UNDL CLR_MAIN << this->contact_infos_keys[i] <<  " :" << RST << endl;
			std::getline(cin, this->_contact_infos_values[i]);
			cout << endl;
			if (cin.eof())
				return;
		}
	}
	cout << CLR_SUCCESS << "Contact " << BOLD CLR_MAIN
		<< this->_contact_infos_values[FIRST_NAME]
		<< " " << this->_contact_infos_values[LAST_NAME]
		<< CLR_SUCCESS << " has been successfully created !\n" << RST << endl;
}

void Contact::eraseContact(void)
{
	for (int i = 0; i < CONTACT_INFOS_QUANTITY; ++i)
		this->_contact_infos_values[i].clear();
}

void Contact::displayContactShort(int index)
{
	cout << std::setfill(FILLER) << std::setw(COL_WIDTH);
	cout << index << " " << SEPARATOR << " ";
	for (int i = 1; i < 4; ++i)
	{
		if (this->_contact_infos_values[i].length() > COL_WIDTH)
		{
			cout << std::setfill(FILLER) << std::right;
			cout << this->_contact_infos_values[i].substr(0, COL_WIDTH - 1) << ".";
		}
		else
		{
			cout << std::setfill(FILLER) << std::right<< std::setw(COL_WIDTH);
			cout << this->_contact_infos_values[i];
		}
		if (i != 3)
			cout << " " << SEPARATOR << " ";
	}
}

void Contact::displayContactFull(void)
{
	for (int i = 0; i < CONTACT_INFOS_QUANTITY; ++i)
	{
		cout << UNDL CLR_MAIN << this->contact_infos_keys[i]
			<< RST << ": " << BOLD CLR_ALT
			<< this->_contact_infos_values[i] << RST << endl;
	}
	cout << endl;
}
