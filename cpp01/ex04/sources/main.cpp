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

	if (ac != 4)
	{
		cout << BAD_ARG << endl;
		return (1);
	}
	try
	{
		if (!sed.openInfile(av[1]))
			return (1);
		if (!sed.createOutfile(av[1]))
			return (1);
		sed.setSeq(av[2], Sed::FROM);
		sed.setSeq(av[3], Sed::TO);
		sed.replaceOccurences();
	}
	catch (const std::ios::failure &error)
	{
		cout << RED << error.what() << RST << endl;
	}
	return (0);
}
