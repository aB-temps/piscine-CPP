/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:39:42 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/24 18:17:33 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

#include "Bureaucrat.hpp"
#include "text_formatting.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char			*AForm::defaultName = "Useless sheet";
const char			*AForm::defaultTarget = "Random";
const t_uint8 		AForm::defaultSignGrade = 42;
const t_uint8 		AForm::defaultExecGrade = 21;


// Constructor & Destructor ====================================================
AForm::AForm(void):
	_name(AForm::defaultName), 
	_target(AForm::defaultTarget), 
	_signGrade(AForm::defaultSignGrade),
	_execGrade(AForm::defaultExecGrade),
	_signed(false) {}

AForm::AForm(const AForm &copy):
	_name(copy._name),
	_target(copy._target),
	_signGrade(copy._signGrade),
	_execGrade(copy._execGrade),
	_signed(copy._signed) {}

AForm::AForm(const std::string &name, const std::string &target, const t_uint8 &sign_grade, const t_uint8 &exec_grade):
	_name(name),
	_target(target),
	_signGrade(sign_grade),
	_execGrade(exec_grade),
	_signed(false)
{
	if (sign_grade < Bureaucrat::maxGrade || exec_grade < Bureaucrat::maxGrade)
		throw (AForm::GradeTooHighException());
	else if (sign_grade > Bureaucrat::minGrade || exec_grade > Bureaucrat::minGrade)
		throw (AForm::GradeTooLowException());
}

AForm::~AForm(void) {}


// Operator Overloads ==========================================================
std::ostream	&operator<<(std::ostream &outstream, const AForm &insert)
{
	outstream	<< "[" BOLD << insert.getName()
				<< RST " | target: " YELLOW << insert.getTarget()
				<< RST " | sign grade: " BLUE << insert.getSignGrade()
				<< RST " | exec grade: " MAGENTA << insert.getExecGrade()
				<< RST " | status:  " << (insert.getStatus() ? GREEN "signed" : RED "unsigned")
				<< RST "]";

	return (outstream);
}

AForm	&AForm::operator=(const AForm &assign)
{
	(void)	assign;
	return (*this);
}

// Getters =====================================================================
const std::string	&AForm::getName(void) const { return (this->_name); }

const std::string	&AForm::getTarget(void) const { return (this->_target); }

const t_uint8		&AForm::getSignGrade(void) const { return (this->_signGrade); }

const t_uint8		&AForm::getExecGrade(void) const { return (this->_execGrade); }

const bool			&AForm::getStatus(void) const { return (this->_signed); }


// Member functions ============================================================
void				AForm::_beSigned(const Bureaucrat &b)
{
	if (this->_signed)
		throw (AForm::AlreadySignedException());
	if (b.getGrade() <= this->_signGrade)
		this->_signed = true;
	else
		throw (AForm::GradeTooLowException());
}

void				AForm::signForm(const Bureaucrat &b)
{
	try
	{
		this->_beSigned(b);
	}
	catch (const AForm::FormException &e)
	{
		cout	<< b << RED BOLD " couldn't sign " RST
				<< *this << " because [" RED BOLD << e.what()
				<< RST "]."<< endl;
		return;
	}
	cout	<< b << GREEN BOLD " signed " RST
			<< *this << endl;
}

void				AForm::_isExecutable(const t_uint8 executorGrade) const
{
	if (!this->_signed)
		throw (AForm::NotSignedException());
	if (executorGrade <= this->_execGrade)
		throw (Bureaucrat::GradeTooLowException());
}


// Exceptions ==================================================================
// Constructor & Destructor ----------------------------------------------------
AForm::FormException::FormException(void):
	GradeException("FormException", "") {}

AForm::FormException::FormException(const char *msg):
	GradeException("FormException", msg) {}

AForm::GradeTooHighException::GradeTooHighException(void):
	FormException("Grade too high") {}

AForm::GradeTooLowException::GradeTooLowException(void):
	FormException("Grade too low") {}

AForm::AlreadySignedException::AlreadySignedException(void):
	FormException("Cannot sign a form that has already been signed") {}

AForm::NotSignedException::NotSignedException(void):
	FormException("Cannot execute a form that has not been signed") {}
