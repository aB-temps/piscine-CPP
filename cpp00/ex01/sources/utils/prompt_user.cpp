/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_user.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/25 14:24:11 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/25 14:28:40 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "utils.hpp"

using	std::cin;
using	std::cout;
using	std::endl;

int	prompt_user(std::string &input, const char *prompt, const char *detail)
{
	cin.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
	while (input.empty() || str_is(input, std::isspace))
	{
		try
		{
			cout 	<< CLR_MAIN BOLD << prompt 
					<< CLR_SCND << (detail ? detail : "" ) << RST << endl 
					<< CLR_ALT << "> " << RST;
			getline(cin, input);
			cout << endl;
		}
		catch (const std::ios::failure &error)
		{
			if (cin.bad())
			{
				put_stream_error(cin.rdstate(), __func__, "getline");
				throw;
			}
			else if (cin.eof())
			{
				cout << LEAVING_M << endl;
				throw;
			}
			else if (cin.fail())
			{
				put_stream_error(cin.rdstate(), __func__, "getline");
				cin.clear();
				input.clear();
				continue;
			}
		}
	}
	return (0);
}
