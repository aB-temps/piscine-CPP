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

#include "Data.hpp"
#include "Serializer.hpp"

using	std::cout;
using	std::endl;

int main(void)
{
	Data		*d1 = new Data("jweber");
	uintptr_t	raw = Serializer::serialize(d1);

	cout << "RAW: " << raw << endl;

	Data	*d2 = Serializer::deserialize(raw);

	cout << "DATA: " << d2->getName() << endl;

	delete	d1;
	return (0);
}
