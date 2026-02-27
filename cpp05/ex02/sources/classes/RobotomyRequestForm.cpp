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

#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "text_formatting.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char		*RobotomyRequestForm::_defaultName = "RobotomyRequestForm";
const t_uint8	RobotomyRequestForm::_defaultSignGrade = 72;
const t_uint8	RobotomyRequestForm::_defaultExecGrade = 45;


// Constructor & Destructor ====================================================
RobotomyRequestForm::RobotomyRequestForm(const char *target):
	AForm(RobotomyRequestForm::_defaultName, target, RobotomyRequestForm::_defaultSignGrade, RobotomyRequestForm::_defaultExecGrade) {}

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


// Member functions ============================================================
void	RobotomyRequestForm::_executeSelf(void) const
{
	cout << YELLOW "Drrrrrrrrrrrrrrrrr!!" << endl;
	std::srand(std::time(0));
	if (std::rand() % 2)
	{
		cout	<< GREEN BOLD
				<< this->getTarget() << RST GREEN "'s robotomy was a success!" RST
				<< endl;
	}
	else
	{
		cout	<< RED BOLD
				<< this->getTarget() << RST RED "'s robotomy failed..." RST
				<< endl;
	}
}
