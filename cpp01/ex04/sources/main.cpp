/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 11:14:22 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Sed.hpp"
#include "errors.hpp"

using	std::cout;
using	std::endl;

int main(int ac, char *av[])
{
	Sed	sed;

	if (!sed.parseArguments(ac, av))
		return (1);
	try
	{
		if (!sed.openInfile(av[1]))
			return (1);
		if (!sed.createOutfile(av[1]))
		{
			sed.closeIOFiles();
			return (1);
		}
		sed.replaceOccurences();
	}
	catch (const std::ios::failure &error)
	{
		sed.closeIOFiles();
		return (1);
	}
	return (0);
}
