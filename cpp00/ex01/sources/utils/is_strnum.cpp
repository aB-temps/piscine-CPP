/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_strnum.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:18:11 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/09 15:29:06 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>

bool	is_strnum(std::string str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}
