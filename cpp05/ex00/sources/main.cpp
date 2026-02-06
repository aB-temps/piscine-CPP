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

#include "Bureaucrat.hpp"

using	std::cout;
using	std::endl;

int main(void)
{
	Bureaucrat b1;
	Bureaucrat b2("Fred", 12);
	Bureaucrat b3(b2);

	cout << b1 << endl;
	cout << b2 << endl;
	cout << b3 << endl;
	return (0);
}
