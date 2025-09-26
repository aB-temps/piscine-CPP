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

#include <iostream>
#include <string>

class Contact
{
	public :
		Contact(void);
		~Contact(void);
		bool	createContact(void);
		void	displayContact(void);

	private :
		std::string _phoneNumber;
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _darkestSecret;
};

#endif
