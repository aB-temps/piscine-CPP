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
#define ERROR	2

int	main(int ac, char **av)
{
	(void) av;
	PhoneBook	phonebook;
	std::string	input;

	if (ac != 1)
	{
		std::cerr << CLR_ERROR << "PhoneBook do not any take arguments." << RST << std::endl;
		return (ERROR);
	}
	std::cout << CLR_MAIN << "Welcome to PhoneBook !" << RST << std::endl;
	while (!std::cin.eof())
	{
		std::cout << CLR_SCND << "What you want to do now ?" << RST << std::endl;
		std::getline(std::cin, input);
		if (input == "ADD")
			phonebook.runFeature(PhoneBook::ADD);
		else if (input == "SEARCH")	
			phonebook.runFeature(PhoneBook::SEARCH);
		else if (input == "EXIT" && ask_confirmation("Are you sure to exit ? All your contacts will be lost forever."))	
		{
			input.clear();
			return (SUCCESS);
		}
		input.clear();
	}
	return (SUCCESS);
}
