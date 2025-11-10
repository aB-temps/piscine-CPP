/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:59:02 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 17:28:13 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__ERRORS_HPP__
# define	__ERRORS_HPP__

# include "text_formatting.hpp"

# define BAD_ARGS 		BOLD""RED"Bad arguments."RST
# define NO_OCC			BOLD""RED"No occurence has been found."RST
# define FAIL_OPEN		BOLD""RED"Infile cannot be opened."RST
# define FAIL_CREATE	BOLD""RED"Outfile cannot be created."RST
# define BADBIT 		BOLD""RED"Fatal error occured."RST


#endif
