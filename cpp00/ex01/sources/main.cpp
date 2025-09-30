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

int	main(void)
{
	PhoneBook phonebook;
	std::string input;

	welcome();
	while (true)
	{
		std::cin >> input;
		if (input.empty())
			return (1);
		if (input == "ADD")
			phonebook.runFeature(PhoneBook::ADD);
		else if (input == "SEARCH")	
			phonebook.runFeature(PhoneBook::SEARCH);
		else if (input == "EXIT")	
			phonebook.runFeature(PhoneBook::EXIT);
		input.clear();

	}
	return (0);
}
