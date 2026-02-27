/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:39:42 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/27 15:59:13 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "text_formatting.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char						*Intern::formNames[Intern::FORMS_QTY] =
{
	"shrubbery creation",
	"robotomy request",
	"presidential pardon"
};

const Intern::formConstructor	Intern::_constructors[Intern::FORMS_QTY] =
{
	&Intern::buildForm<ShrubberyCreationForm>,
	&Intern::buildForm<RobotomyRequestForm>,
	&Intern::buildForm<PresidentialPardonForm>
};

// Constructor & Destructor ====================================================
Intern::Intern(void) {}

Intern::Intern(const Intern &copy)
{
	(void) copy;
}

Intern::~Intern(void) {}


// Operator Overloads ==========================================================
Intern	&Intern::operator=(const Intern &assign)
{
	(void)	assign;
	return (*this);
}


// Member functions ============================================================
AForm	*Intern::makeForm(const std::string &name, const std::string &target)
{
	for (t_uint8 i = 0; i < FORMS_QTY; ++i)
	{
		if (name == Intern::formNames[i])
			return (Intern::_constructors[i](target.c_str()));
	}
	throw (Intern::UnknownFormException());
}


// Exceptions ==================================================================
// Constructor & Destructor ----------------------------------------------------
Intern::InternException::InternException(void):
	GradeException("InternException", "") {}

Intern::InternException::InternException(const char *msg):
	GradeException("InternException", msg) {}

Intern::UnknownFormException::UnknownFormException(void):
	InternException("Unknown Form") {}
