/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 19:25:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/09/25 19:25:23 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iomanip>
# include "style.hpp"

# define COL_WIDTH	10

class Contact
{
	public :
		Contact(void);
		~Contact(void);
		enum		e_ContactInfos
		{
			PHONE,
			FIRST_NAME,
			LAST_NAME,
			NICK_NAME,
			DARK_SECRET,
			CONTACT_INFOS_QUANTITY,
		};
		const char	*contact_infos_keys[CONTACT_INFOS_QUANTITY];
		void		createContact(void);
		void		eraseContact(void);
		void		displayContactInformations(int index);
		
	private :
		typedef std::string 		_ContactInfosValuesArray[CONTACT_INFOS_QUANTITY];
		_ContactInfosValuesArray	_contact_infos_values;
};

#endif
