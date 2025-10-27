/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:25:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/24 18:40:31 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__CONTACT_HPP__
# define	__CONTACT_HPP__

# include "errors.hpp"
# include "utils.hpp"

# define COL_WIDTH	10

class Contact
{
	public :
		Contact(void);
		enum						e_ContactInfos
		{
			PHONE,
			FIRST_NAME,
			LAST_NAME,
			NICK_NAME,
			DARK_SECRET,
			CONTACT_INFOS_QUANTITY,
		};
		typedef const char				*ContactInfosKeysArray[CONTACT_INFOS_QUANTITY];
		ContactInfosKeysArray contact_infos_keys;
		void						createContact(void);
		void						eraseContact(void);
		void						displayContactShort(int index);
		void						displayContactFull(void);
		
	private :
		typedef std::string 		_ContactInfosValuesArray[CONTACT_INFOS_QUANTITY];
		_ContactInfosValuesArray	_contact_infos_values;
};

#endif
