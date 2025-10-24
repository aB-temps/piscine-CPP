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

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <cctype>
# include "Contact.hpp"

# define MAX_CONTACTS 8

class PhoneBook
{
	public :
		PhoneBook(void);
		int				startPhonebook(void)
		enum			e_Features
		{
			ADD,
			SEARCH,
			EXIT,
			FEATURES_QUANTITY
		};
	
	private :
		typedef int		(PhoneBook::*FeaturesArray)(void);
		Contact			_contacts[MAX_CONTACTS];
		FeaturesArray	_features[FEATURES_QUANTITY];
		int				_contact_quantity;
		int				_runFeature(e_Features feat);
		int				_addContact(void);
		int				_searchContact(void);
		void			_displayContacts(void);
		int				_exitPhoneBook(void);
};

#endif
