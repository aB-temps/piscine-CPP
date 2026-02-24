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
#include "Form.hpp"

using	std::cout;
using	std::endl;

int main(void)
{
	try
	{
		Bureaucrat	b1("Mark", 1);
		Bureaucrat	b2("Fred", 42);
		
		Form		f1("Application of jweber", 10, 5);
		Form		f2("Jweber's application's scandal", 0, 151);
	}
	catch (const GradeException &e) // catches wheiter a Bureaucrat's or Forms's GradeException(tooLow, tooHigh)
	{
		cout << e.what() << endl;
	}

	try
	{
		Bureaucrat	b1("Mark", 1);
		Bureaucrat	b2("Fred", 42);

		Form		f1("Application of jweber", 10, 5);
		Form		f2("Application of civel", 10, 5);

		f1.signForm(b1); // OK

		f1.signForm(b2); // KO: Already signed

		f2.signForm(b2); // KO: Grade too low

		Form		f3("Application of qpupier", 0, 5); // KO: Grade too high (Form)
		++b1;											// KO: Grade too high (Bureaucrat)
	}
	catch (const Form::FormException &e) // do not exits program
	{
		cout << e.what() << endl;
	}
	catch (const Bureaucrat::BureaucratException &e) // exits program
	{
		cout << e.what() << endl;
		return (1);
	}

	return (0);
}
