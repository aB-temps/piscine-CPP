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
	catch (const GradeException &e)
	{
		cout << e.what() << endl; // catches wheiter a Bureaucrat's or Forms's GradeException(tooLow, tooHigh)
	}

	try
	{
		Bureaucrat	b1("Mark", 1);
		Bureaucrat	b2("Fred", 42);

		Form		f1("Application of jweber", 10, 5);

		f1.signForm(b1);
		f1.signForm(b2);
	}
	catch (const GradeException &e)
	{
		cout << e.what() << endl; // catches wheiter a Bureaucrat's or Forms's GradeException(tooLow, tooHigh)
	}

	return (0);
}
