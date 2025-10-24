/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 18:42:44 by abetemps          #+#    #+#             */
/*   Updated: 2025/09/27 20:22:23 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include "style.hpp"

#define SUCCESS	0
#define I_ERROR	1
#define U_ERROR	2

int	main(int ac, char **av)
{
	(void) av;
	PhoneBook	phonebook;
	std::string	input;

	if (ac != 1)
	{
		std::cout << CLR_ERROR << "PhoneBook do not any take arguments." << RST << std::endl;
		return (U_ERROR);
	}
	std::cout << CLR_MAIN << "Welcome to PhoneBook !" << RST << std::endl;
	while (!std::cin.eof())
	{
		std::cout << CLR_SCND << "What you want to do now ?" << std::endl;
		std::cout << DIM << "ADD, SEARCH or EXIT\n" << RST << std::endl << "> ";
		std::getline(std::cin, input);
		if (std::cin.bad())
		{
			std::cout << CLR_ERROR << "Error occured while getting your input. Leaving.\n" << RST << std::endl;
			return (I_ERROR);
		}
		else if (std::cin.fail())
		{
			std::cout << CLR_ERROR << "Format error or conversion failure your input. Leaving.\n" << RST << std::endl;
			return (U_ERROR);
		}
		if (input == "ADD")
			phonebook.runFeature(PhoneBook::ADD);
		else if (input == "SEARCH")	
			phonebook.runFeature(PhoneBook::SEARCH);
		else if (input == "EXIT" && ask_confirmation("Are you sure to exit ? All your contacts will be lost forever."))	
			return (SUCCESS);
		else
			std::cout << CLR_ERROR << "Invalid command.\n" << RST << std::endl;
		std::cout << std::endl;
	}
	return (SUCCESS);
}
