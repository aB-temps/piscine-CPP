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
	try
	{
		Bureaucrat b1;
		Bureaucrat b2("Fred", 1);
		Bureaucrat b3("Mike", 150);
		Bureaucrat b4(b2);

		cout << b1 << endl;

		cout << b1++ << endl;
		cout << b1 << endl;
		cout << ++b1 << endl;

		cout << --b2 << endl;

		cout << --b3 << endl;
	}
	catch (const Bureaucrat::GradeException &e)
	{
		cout << e.name() << ": " << e.what() << endl;
		return (1);
	}

	return (0);
}
