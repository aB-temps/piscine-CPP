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

	Bureaucrat				b1("Enchevri", 1);
	f1.signForm(b1);
	b1.executeForm(f1);

	return (0);
}
