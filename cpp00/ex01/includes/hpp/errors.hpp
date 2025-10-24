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
# define ERR_INV_ARG	"PhoneBook do not any take argument. Leaving.\n"
# define ERR_INV_CMD	"Invalid command.\n"

// STREAM ERROR
# define ERR_M_FAILBIT 	"Format error or conversion failure.\n"
# define ERR_M_BADBIT	"Hardware failure or corrupted stream.\n"

#endif
