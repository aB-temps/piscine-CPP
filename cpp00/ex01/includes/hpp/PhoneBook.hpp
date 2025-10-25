/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:03:04 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/24 20:12:16 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__PHONEBOOK_H__
# define	__PHONEBOOK_H__

# include <cctype>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	public :
		PhoneBook(void);
		int				startPhoneBook(void);
	
	private :
		enum			_e_Features
		{
			ADD,
			SEARCH,
			EXIT,
			FEATURE_QUANTITY
		};
		typedef int		(PhoneBook::*FeaturesArray)(void);
		Contact			_contacts[MAX_CONTACTS];
		FeaturesArray	_features[FEATURE_QUANTITY];
		int				_contact_quantity;
		int				_runFeature(_e_Features feat);
		int				_addContact(void);
		int				_searchContact(void);
		void			_displayContacts(void);
		int				_exitPhoneBook(void);
};

#endif
