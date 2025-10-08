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

#include "style.hpp"

bool	ask_confirmation(std::string message)
{
	std::string input;

	while (input.empty() && !std::cin.eof())
	{
		std::cout << std::endl << CLR_WARN << message << RST << "\nConfirm [Y/N]" << std::endl;
		std::getline(std::cin, input);
		if (input == "Y" || input == "y")
			return (true);
		else if (input == "N" || input == "n")
			return (false);
	}
	return (false);
}
