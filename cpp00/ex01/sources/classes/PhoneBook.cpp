/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:01:47 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/24 17:12:59 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>
#include "PhoneBook.hpp"

using	std::cin;
using	std::cout;
using	std::endl;

PhoneBook::PhoneBook(void)
{
	this->_contact_quantity = 0;
	this->_features[ADD] = &PhoneBook::_addContact;
	this->_features[SEARCH] = &PhoneBook::_searchContact;
	this->_features[EXIT] = &PhoneBook::_exitPhoneBook;
}


int	PhoneBook::startPhoneBook(void)
{
	std::string	input;

	cout << WELCOME_M << endl;
	while (true)
	{
		try 
		{
			prompt_user(input, PRM, PRM_HOME);
			if (input == "ADD")
				this->_runFeature(ADD);
			else if (input == "SEARCH")
				this->_runFeature(SEARCH);
			else if (input == "EXIT")
			{
				if (!this->_runFeature(EXIT))
					return (SUCCESS);
			}
			else
				cout << ERR_INV_CMD << endl;
			input.clear();
		}
		catch (const std::ios_base::failure& error)
		{
			if (cin.bad())
				return (I_ERROR);
			else if (cin.eof())
				break;
		}
	}
	return (SUCCESS);
}

int	PhoneBook::_runFeature(_e_Features feat)
{
	return (this->*_features[feat])();
}

int	PhoneBook::_addContact(void)
{
	static int oldest_contact_index;

	if (this->_contact_quantity == MAX_CONTACTS)
	{
		cout << ERR_MAX_CONTACT << endl;
		if (ask_confirmation(CONF_REP_CONTACT))
		{
			this->_contacts[oldest_contact_index].eraseContact();
			this->_contacts[oldest_contact_index++].createContact();
			oldest_contact_index %= MAX_CONTACTS;
		}
	}
	else
	{
		this->_contacts[this->_contact_quantity].createContact();
		++this->_contact_quantity;
	}
	return (0);
}

void	PhoneBook::_displayContacts(void)
{
	cout << CLR_ALT << CORNER_TOP_LEFT;
	for (int i = 0; i < ((COL_WIDTH + 2) * 4) + 3; ++i)
		cout << FLOOR;
	cout << CORNER_TOP_RIGHT << RST << endl;
	for (int i = 0; i < this->_contact_quantity; ++i)
	{
		cout << CLR_ALT << WALL << " " << RST;
		this->_contacts[i].displayContactShort(i + 1);
		cout << CLR_ALT << " " << WALL << endl;

	}	
	cout << CLR_ALT << CORNER_BOTTOM_LEFT;
	for (int i = 0; i < ((COL_WIDTH + 2) * 4) + 3; ++i)
		cout << FLOOR;
	cout << CORNER_BOTTOM_RIGHT << RST << endl;
}

int	PhoneBook::_searchContact(void)
{
	std::string			input;
	std::stringstream	ss_input;
	int					index;

	if (!this->_contact_quantity)
	{
		cout << WARN_NO_CONTACT << endl;
		return (U_ERROR);
	}
	this->_displayContacts();
	cout << BOLD CLR_MAIN << this->_contact_quantity << RST << "/" << MAX_CONTACTS << " contacts registered\n" << endl;
	while (true)
	{
		prompt_user(input, PRM, PRM_SEARCH);
		if (str_is(input, isdigit))
		{
			ss_input << input;
			ss_input >> index;
			if (index >= 1 && index <= this->_contact_quantity)
				this->_contacts[index - 1].displayContactFull();
			else if (index > 0 && ask_confirmation(CONF_NOT_IN_RANGE))
				this->_addContact();
		}
		else if (input == "HOME")
			return (SUCCESS);
		else
			cout << ERR_INV_CMD << endl;
		input.clear();
		ss_input.clear();
	}
	return (SUCCESS);
}

int	PhoneBook::_exitPhoneBook(void)
{
	if (ask_confirmation(CONF_EXIT))
	{
		cout << LEAVING_M << endl;
		return (0);
	}
	cout << CLR_MAIN << "Aborting." << RST << endl;
	return (1);
}
