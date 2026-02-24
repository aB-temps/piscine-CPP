/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/24 18:24:45 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/24 18:24:56 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char		*RobotomyRequestForm::defaultName = "RobotomyRequestForm";
const t_uint8	RobotomyRequestForm::defaultSignGrade = 72;
const t_uint8	RobotomyRequestForm::defaultExecGrade = 45;

// Constructor & Destructor ====================================================
RobotomyRequestForm::RobotomyRequestForm(const char *target):
	AForm(RobotomyRequestForm::defaultName, target, RobotomyRequestForm::defaultSignGrade, RobotomyRequestForm::defaultExecGrade) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &copy):
	AForm()
{
	(void) copy;
}

RobotomyRequestForm::~RobotomyRequestForm(void) {}

// Operator Overloads ==========================================================
RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm &assign)
{
	(void) assign;
	return (*this);
}

// Getters =====================================================================


// Member functions ============================================================


// Exceptions ==================================================================
