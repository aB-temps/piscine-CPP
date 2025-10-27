/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ask_confirmation.cpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 17:10:43 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/08 17:26:19 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "utils.hpp"
#include "style.hpp"

bool	ask_confirmation(const char* message)
{
	std::string input;

	while (input.empty())
	{
		prompt_user(input, message, PROMPT_CONF);
		if (input == "Y" || input == "y")
			return (true);
		else if (input == "N" || input == "n")
			return (false);
		else
			input.clear();
	}
	return (false);
}
