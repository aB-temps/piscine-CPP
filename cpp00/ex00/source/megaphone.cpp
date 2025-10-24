/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 14:32:34 by abetemps          #+#    #+#             */
/*   Updated: 2025/09/21 14:32:40 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

#define DEFAULT_MESSAGE "* LOUD AND UNBEARABLE FEEDBACK NOISE *"

int	main(int ac, char **av)
{
	int j;

	if (ac < 2)
		std::cout << DEFAULT_MESSAGE << std::endl;
	else
	{
		for (int i = 1 ; i < ac ; ++i)
		{
			j = 0;
			while (av[i][j])
			{
				std::cout << static_cast<unsigned char>(std::toupper(av[i][j]));
				++j;
			}
		}
		std::cout << std::endl;
	}
	return (0);
}

