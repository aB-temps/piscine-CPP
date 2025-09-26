/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   welcome.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/27 00:45:09 by abetemps          #+#    #+#             */
/*   Updated: 2025/09/27 01:21:29 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "text_formatting.h"

void welcome(void)
{
	std::cout << BLUE << "Welcome to PhoneBook !" << std::endl << GREEN << "What you want to do now ?" << RST << std::endl;
 }
