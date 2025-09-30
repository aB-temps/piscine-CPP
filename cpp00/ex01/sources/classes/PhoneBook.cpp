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
	this->contact_quantity = 0;
	this->features[ADD] = &PhoneBook::addContact;
	this->features[SEARCH] = &PhoneBook::searchContact;
	this->features[EXIT] = &PhoneBook::exitPhoneBook;
	std::cout << "PhoneBook created !" << std::endl;
}

PhoneBook::~PhoneBook(void)
{
	std::cout << "PhoneBook destructed..." << std::endl; 
}

void PhoneBook::runFeature(e_Features feat)
{
	(this->*features[feat])();
}

void PhoneBook::addContact(void)
{
	this->contact_quantity++;
	std::cout << "AddContact" << std::endl;
}

void PhoneBook::searchContact(void)
{
	std::cout << "SearchContact" << std::endl;
	std::cout << this->contact_quantity << std::endl;
}

void PhoneBook::exitPhoneBook(void)
{
	std::cout << "hop" << std::endl;
}
