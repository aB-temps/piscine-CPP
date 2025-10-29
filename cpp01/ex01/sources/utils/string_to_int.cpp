/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_to_int.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 21:05:00 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/27 21:13:43 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sstream>

void	string_to_int(int &value, std::string str)
{
	std::stringstream ss(str);
	ss >> value;
}
