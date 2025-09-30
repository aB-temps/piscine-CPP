/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 16:03:04 by abetemps          #+#    #+#             */
/*   Updated: 2025/09/27 23:07:26 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include <cctype>
# include "Contact.hpp"

class PhoneBook
{
	public :
	PhoneBook(void);
	~PhoneBook(void);
	enum e_Features
	{
		ADD,
		SEARCH,
		EXIT,
		FEATURES_QUANTITY
	};
	void runFeature(e_Features feat);

	private :
		typedef void (PhoneBook::*FeaturesArray)(void);
		Contact			contacts[8];
		int				contact_quantity;
		FeaturesArray	features[FEATURES_QUANTITY];
		void			addContact(void);
		void			searchContact(void);
		void			exitPhoneBook(void);
};

#endif
