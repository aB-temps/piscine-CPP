/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:07:27 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 10:17:43 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

#define DEFAULT_STRING "HI THIS IS BRAIN"

using	std::cout;
using	std::endl;

int	main(void)
{
	std::string str(DEFAULT_STRING);
	std::string	*stringPTR = &str;
	std::string	&stringREF(str);

	cout 	<< "&str: "		<< &str << endl
			<< "strPTR: "	<< &stringPTR << endl
			<< "strREF: "	<< &stringREF << endl;

	cout 	<< "\nstr: "	<< str << endl
			<< "strPTR: "	<< *stringPTR << endl
			<< "strREF: "	<< stringREF << endl;

	return (0);
}
