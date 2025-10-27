/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 18:18:41 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/08 18:19:31 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__UTILS_HPP__
# define	__UTILS_HPP__

#include <string>
#include "errors.hpp"

// CONFIRMATION PROMPTS
# define PROMPT_CONF		"Confirm [Yy/Nn]\n"
# define CONF_EXIT			"Are you sure to exit ? All your contacts will be lost forever.\n"
# define CONF_REP_CONTACT	"Would you like to replace the oldest contact ?\n"
# define CONF_NOT_IN_RANGE	"Not in range. Would you like to add a new contact ?\n"

// GREETER/GOOD_BYER
# define WELCOME_M			CLR_MAIN "Welcome to " BOLD "PhoneBook !\n" RST
# define LEAVING_M			CLR_MAIN "Leaving.\n\nSee you later on " BOLD "PhoneBook !\n" RST

// PROMPTS
# define PROMPT				CLR_MAIN BOLD "What do you want to do ?\n" RST
# define PROMPT_HOME		CLR_SCND "You can " BOLD "ADD" RST CLR_SCND " contact, " BOLD "SEARCH" RST CLR_SCND " for contacts, or " BOLD "EXIT" RST CLR_SCND " PhoneBook.\n"
# define PROMPT_SEARCH		CLR_SCND "Enter a " BOLD "contact index" RST CLR_SCND " to see full informations or " BOLD "HOME" RST CLR_SCND " to go back to main menu." RST

bool	ask_confirmation(const char *message);
bool	str_is(std::string str, int (*check)(int));
int		put_stream_error(int state, const char *func, const char *calling_func);
int		prompt_user(std::string &input, const char *prompt, const char *detail);

#endif
