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
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

enum
{
	SUCCESS,
	FATAL_IOS
};

using	std::cout;
using	std::endl;

int main(void)
{
	ShrubberyCreationForm	f1("JM");
	RobotomyRequestForm		f2("JP");
	PresidentialPardonForm	f3("JF");

	cout	<< f1 << '\n'
			<< f2 << '\n'
			<< f3 << endl;

	Bureaucrat				b1("Enchevri", 136);
	Bureaucrat				b2("Pde-petr", 42);
	Bureaucrat				b3("Cviel", 5);

	cout	<< b1 << '\n'
			<< b2 << '\n'
			<< b3 << endl;


	b1.signForm(f1);
	try
	{
		b1.executeForm(f1);
	}
	catch (const std::ios::failure &e) // dedicated exception's return code
	{
		return (FATAL_IOS);
	}


	b2.signForm(f2);
	b2.executeForm(f2);



	b3.signForm(f3);
	b3.executeForm(f3);

	return (SUCCESS);
}
