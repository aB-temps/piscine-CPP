/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:39:42 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/07 18:07:55 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

#include "Form.hpp"
#include "text_formatting.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char			*Bureaucrat::defaultName = "Anonymous";
const t_uint8		Bureaucrat::minGrade = 150;
const t_uint8 		Bureaucrat::maxGrade = 1;
const t_uint8 		Bureaucrat::defaultGrade = Bureaucrat::minGrade;

// Constructor & Destructor ====================================================
Bureaucrat::Bureaucrat(void):
	_name(Bureaucrat::defaultName), 
	_grade(Bureaucrat::defaultGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):
	_name(copy._name),
	_grade(copy._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, const int &grade):
	_name(name),
	_grade(grade)
{
	if (grade < Bureaucrat::maxGrade)
		throw (Bureaucrat::GradeTooHighException());
	else if (grade > Bureaucrat::minGrade)
		throw (Bureaucrat::GradeTooLowException());
}

Bureaucrat::~Bureaucrat(void) {}


// Operator Overloads ==========================================================
std::ostream	&operator<<(std::ostream &outstream, const t_uint8 &insert)
{
	outstream << +insert;

	return (outstream);
}

std::ostream	&operator<<(std::ostream &outstream, const Bureaucrat &insert)
{
	outstream	<< "[" BOLD << insert.getName()
				<< RST ", bureaucrat grade " << insert.getGrade()
				<< "]";

	return (outstream);
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &assign)
{
	if (this != &assign)
	{
		this->_name = assign._name;
		this->_grade = assign._grade;
	}
	return (*this);
}

Bureaucrat		&Bureaucrat::operator++(void)
{
	this->upGrade();

	return (*this);
}

Bureaucrat		Bureaucrat::operator++(int)
{
	Bureaucrat tmp(*this);

	this->upGrade();

	return (tmp);
}

Bureaucrat		&Bureaucrat::operator--(void)
{
	this->downGrade();

	return (*this);
}

Bureaucrat		Bureaucrat::operator--(int)
{
	Bureaucrat tmp(*this);

	this->downGrade();

	return (tmp);
}


// Getters =====================================================================
const std::string	&Bureaucrat::getName(void) const { return (this->_name); }

const t_uint8		&Bureaucrat::getGrade(void) const { return (this->_grade); }

void				Bureaucrat::upGrade(void)
{
	if (this->_grade - 1 < Bureaucrat::maxGrade)
		throw (Bureaucrat::GradeTooHighException());
	--this->_grade;
}

void				Bureaucrat::downGrade(void)
{
	if (this->_grade + 1 > Bureaucrat::minGrade)
		throw (Bureaucrat::GradeTooLowException());
	++this->_grade;
}

void				Bureaucrat::signForm(Form &f)
{
	try
	{
		f.beSigned(*this);
	}
	catch (const Form::FormException &e)
	{
		cout	<< *this << RED BOLD " couldn't sign " RST
				<< f << " because [" RED BOLD << e.what()
				<< RST "]."<< endl;
		return;
	}
	cout	<< *this << GREEN BOLD " signed " RST
			<< f << endl;
}

// Exceptions ==================================================================
// Constructor & Destructor ----------------------------------------------------
Bureaucrat::BureaucratException::BureaucratException(void):
	GradeException("BureaucratException", "") {}

Bureaucrat::BureaucratException::BureaucratException(const char *msg):
	GradeException("BureaucratException", msg) {}

Bureaucrat::GradeTooHighException::GradeTooHighException(void):
	BureaucratException("Grade too high") {}

Bureaucrat::GradeTooLowException::GradeTooLowException(void):
	BureaucratException("Grade too low") {}
