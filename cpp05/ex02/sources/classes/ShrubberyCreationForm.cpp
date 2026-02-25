/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:24:58 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/24 18:25:06 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char		*ShrubberyCreationForm::defaultName = "ShrubberyCreationForm";
const t_uint8	ShrubberyCreationForm::defaultSignGrade = 145;
const t_uint8	ShrubberyCreationForm::defaultExecGrade = 137;


// Constructor & Destructor ====================================================
ShrubberyCreationForm::ShrubberyCreationForm(const char *target):
	AForm(ShrubberyCreationForm::defaultName, target, ShrubberyCreationForm::defaultSignGrade, ShrubberyCreationForm::defaultExecGrade) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &copy):
	AForm()
{
	(void) copy;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {}


// Operator Overloads ==========================================================
ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm &assign)
{
	(void) assign;
	return (*this);
}


// Member functions ============================================================
void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	this->_isExecutable(executor.getGrade());
}


// Exceptions ==================================================================
