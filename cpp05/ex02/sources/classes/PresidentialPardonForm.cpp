/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:24:19 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/24 18:24:43 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char		*PresidentialPardonForm::defaultName = "PresidentialPardonForm";
const t_uint8	PresidentialPardonForm::defaultSignGrade = 25;
const t_uint8	PresidentialPardonForm::defaultExecGrade = 5;


// Constructor & Destructor ====================================================
PresidentialPardonForm::PresidentialPardonForm(const char *target):
	AForm(PresidentialPardonForm::defaultName, target, PresidentialPardonForm::defaultSignGrade, PresidentialPardonForm::defaultExecGrade) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy):
	AForm()
{
	(void) copy;
}

PresidentialPardonForm::~PresidentialPardonForm(void) {}


// Operator Overloads ==========================================================
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &assign)
{
	(void) assign;
	return (*this);
}


// Member functions ============================================================
void	PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	this->_isExecutable(executor.getGrade());
}


// Exceptions ==================================================================
