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

using std::cout;
using std::endl;

int	main(int ac, char **av)
{
	(void) av;
	PhoneBook	phonebook;

	if (ac != 1)
	{
		cout << CLR_ERROR << ERR_INV_ARG << RST << endl;
		return (U_ERROR);
	}
	if (phonebook.startPhoneBook() == I_ERROR)
		return (I_ERROR);
	return (SUCCESS);
}
