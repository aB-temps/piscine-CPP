/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_is.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/09 15:18:11 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/09 18:12:11 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

bool	str_is(std::string str, int (*check)(int))
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!check(str[i]))
			return (false);
	}
	return (true);
}
