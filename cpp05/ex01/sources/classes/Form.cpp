/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:39:42 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/07 18:11:17 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "text_formatting.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char			*Form::defaultName = "Useless sheet";
const t_uint8 		Form::defaultSignGrade = 42;
const t_uint8 		Form::defaultExecGrade = 21;


// Constructor & Destructor ====================================================
Form::Form(void):
	_name(Form::defaultName), 
	_sign_grade(Form::defaultSignGrade),
	_exec_grade(Form::defaultExecGrade),
	_signed(false) {}

Form::Form(const Form &copy):
	_name(copy._name),
	_sign_grade(copy._sign_grade),
	_exec_grade(copy._exec_grade),
	_signed(copy._signed) {}

Form::Form(const std::string &name, const int &sign_grade, const int &exec_grade):
	_name(name),
	_sign_grade(sign_grade),
	_exec_grade(exec_grade),
	_signed(false)
{
	if (sign_grade < Bureaucrat::maxGrade || exec_grade < Bureaucrat::maxGrade)
		throw (Form::GradeTooHighException());
	else if (sign_grade > Bureaucrat::minGrade || exec_grade > Bureaucrat::minGrade)
		throw (Form::GradeTooLowException());
}

Form::~Form(void) {}


// Operator Overloads ==========================================================
std::ostream	&operator<<(std::ostream &outstream, const Form &insert)
{
	outstream	<< "[" BOLD << insert.getName()
				<< RST " | sign grade: " BLUE << insert.getSignGrade()
				<< RST " | exec grade: " MAGENTA << insert.getExecGrade()
				<< RST " | status:  " << (insert.getStatus() ? GREEN "signed" : RED "unsigned")
				<< RST "]";

	return (outstream);
}

Form	&Form::operator=(const Form &assign)
{
	(void)	assign;
	return (*this);
}

// Getters =====================================================================
const std::string	&Form::getName(void) const { return (this->_name); }

const t_uint8		&Form::getSignGrade(void) const { return (this->_sign_grade); }

const t_uint8		&Form::getExecGrade(void) const { return (this->_exec_grade); }

const bool			&Form::getStatus(void) const { return (this->_signed); }


// Member functions ============================================================
void				Form::beSigned(const Bureaucrat &b)
{
	if (this->_signed)
		throw (Form::AlreadySignedException());
	if (b.getGrade() <= this->_sign_grade)
		this->_signed = true;
	else
		throw (Form::GradeTooLowException());
}


// Exceptions ==================================================================
// Constructor & Destructor ----------------------------------------------------
Form::FormException::FormException(void):
	GradeException("FormException", "") {}

Form::FormException::FormException(const char *msg):
	GradeException("FormException", msg) {}

Form::GradeTooHighException::GradeTooHighException(void):
	FormException("Grade too high") {}

Form::GradeTooLowException::GradeTooLowException(void):
	FormException("Grade too low") {}

Form::AlreadySignedException::AlreadySignedException(void):
	FormException("Already signed") {}
