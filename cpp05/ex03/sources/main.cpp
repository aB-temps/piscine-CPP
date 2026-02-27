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
#include "AForm.hpp"
#include "Intern.hpp"

enum
{
	SUCCESS,
	FATAL_MEM,
	FATAL_INTERN
};

using	std::cout;
using	std::endl;

int main(void)
{
	Intern	i1;

	AForm	*f1;
	AForm	*f2;
	AForm	*f3;
	AForm	*f4;

	try 
	{
		f1 = i1.makeForm("shrubbery creation", "JM");
		f2 = i1.makeForm("robotomy request", "JP");
		f3 = i1.makeForm("presidential pardon", "JF");
		f4 = i1.makeForm("Form", "JF");
	}
	catch (const std::bad_alloc &ba)
	{
		cout << ba.what() << endl;
		return (FATAL_MEM);
	}
	catch (const Intern::InternException &ie)
	{
		cout << ie.what() << endl;
		return (FATAL_INTERN);
	}
	return (SUCCESS);
}
