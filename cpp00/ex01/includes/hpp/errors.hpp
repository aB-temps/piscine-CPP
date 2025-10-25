/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 13:28:09 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/24 18:54:22 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		ERRORS_H
# define	ERRORS_H 

# include "style.hpp"

// ERROR TYPES
# define SUCCESS		0
# define I_ERROR		1
# define U_ERROR		2

// PHONEBOOK ERROR MESSAGES
# define ERR_INV_ARG		CLR_ERROR "PhoneBook do not any take argument. Leaving.\n" RST
# define ERR_INV_CMD		CLR_ERROR "Invalid command.\n" RST
# define ERR_MAX_CONTACT	CLR_ERROR "You have reached the contact limit.\n" RST

// PHONEBOOK WARN MESSAGES
# define WARN_NO_CONTACT	CLR_WARN "No contact registered.\n" RST

// STREAM ERROR
# define ERR_M_FAILBIT 		CLR_ERROR "Format error or conversion failure.\nPlease retry.\n" RST
# define ERR_M_BADBIT		CLR_ERROR "Hardware failure or corrupted stream.\nLeaving.\n" RST

#endif
