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

#include <ctime>
#include <cstdlib>
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
	std::srand(std::time(0));

	unsigned char	error = SUCCESS;
	AForm			*forms[4] = {0};
	Intern			i1;

	try 
	{
		forms[0] = i1.makeForm("shrubbery creation", "JM");
		forms[1] = i1.makeForm("robotomy request", "JP");
		forms[2] = i1.makeForm("presidential pardon", "JF");
		forms[3] = i1.makeForm("Form", "JF");
	}
	catch (const std::bad_alloc &ba)
	{
		cout << ba.what() << endl;
		error = FATAL_MEM;
	}
	catch (const Intern::InternException &ie)
	{
		cout << ie.what() << endl;
		error = FATAL_INTERN;
	}
	for (int i = 0; forms[i]; ++i)
		delete forms[i];
	return (error);
}
