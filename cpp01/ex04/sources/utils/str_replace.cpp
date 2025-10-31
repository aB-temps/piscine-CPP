/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 15:22:43 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/31 15:24:42 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

std::string	str_replace(std::string str, std::string sq1, std::string sq2)
{
	unsigned long	pos = str.find(sq1);

	while (pos != str.npos)
	{
		str.erase(pos, sq1.length()).insert(pos, sq2);
		pos = str.find(sq1);
	}
	return (str);
}
