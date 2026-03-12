/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/06 18:39:27 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

using	std::cout;
using	std::endl;

int main(int ac, char *av[])
{
	if (ac < 2)
		return (1);
	for (int i = 1; av[i]; ++i)
	{
		cout << "=> " <<  av[i] << endl;
		ScalarConverter::convert(av[i]);
		cout << endl;
	}

	return (0);
}
