/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 14:32:00 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/10 13:19:22 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

using		std::cout;
using		std::endl;

// Constructors/Destructor ==============================================================
Serializer::Serializer(void) {}

// Operator overloads ===================================================================
// Serializer		&Serializer::operator=(const Serializer &assign)
// {
// 	if (this != &assign)
// 	{
//
// 	}
// 	return (*this);
// }

// Member function ======================================================================
uintptr_t	Serializer::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data *>(raw));
}
