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
#include "text_formatting.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char		*PresidentialPardonForm::_defaultName = "PresidentialPardonForm";
const t_uint8	PresidentialPardonForm::_defaultSignGrade = 25;
const t_uint8	PresidentialPardonForm::_defaultExecGrade = 5;


// Constructor & Destructor ====================================================
PresidentialPardonForm::PresidentialPardonForm(const char *target):
	AForm(	PresidentialPardonForm::_defaultName,
			target,
			PresidentialPardonForm::_defaultSignGrade,
			PresidentialPardonForm::_defaultExecGrade	) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &copy): AForm() { (void) copy; }

PresidentialPardonForm::~PresidentialPardonForm(void) {}


// Operator Overloads ==========================================================
PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm &assign)
{
	(void) assign;
	return (*this);
}


// Member functions ============================================================
void	PresidentialPardonForm::_executeSelf(void) const
{
	cout	<< YELLOW BOLD
			<< this->getTarget()
			<< RST YELLOW " has been pardoned by "
			<< BOLD "Zaphod Beeblebrox" RST YELLOW << "." RST
			<< endl;
}
