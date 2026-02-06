/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:39:42 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/06 18:57:15 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char			*Bureaucrat::defaultName = "Anonymous";
const t_uint8		Bureaucrat::minGrade = 150;
const t_uint8 		Bureaucrat::maxGrade = 1;
const t_uint8 		Bureaucrat::defaultGrade = Bureaucrat::minGrade;

const char			*Bureaucrat::GradeException::_name = "Bureaucrat_Grade_Exception";


// Constructor & Destructor ====================================================
Bureaucrat::Bureaucrat(void):
	_name(Bureaucrat::defaultName), 
	_grade(Bureaucrat::defaultGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):
	_name(copy._name),
	_grade(copy._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, const t_uint8 &grade):
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
	outstream	<< insert.getName()
				<< ", bureaucrat grade " << insert.getGrade()
				<< ".";

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
	if (this->_grade - 1< Bureaucrat::maxGrade)
		throw (Bureaucrat::GradeTooHighException());
	--this->_grade;
}

void				Bureaucrat::downGrade(void)
{
	if (this->_grade + 1 > Bureaucrat::minGrade)
		throw (Bureaucrat::GradeTooLowException());
	++this->_grade;
}

// Exceptions ==================================================================
// Constructor & Destructor ----------------------------------------------------
Bureaucrat::GradeException::GradeException(const char *msg): _msg(msg) {}

Bureaucrat::GradeTooHighException::GradeTooHighException(void): GradeException("Grade too high.") {}

Bureaucrat::GradeTooLowException::GradeTooLowException(void): GradeException("Grade too low.") {}

// what() overload -------------------------------------------------------------
const char	*Bureaucrat::GradeException::name(void) const { return (this->_name); }

const char	*Bureaucrat::GradeException::what(void) const throw() { return (this->_msg); }


// const char	*Bureaucrat::GradeTooHighException::what(void) const throw() { return ("Grade too high."); }
//
// const char	*Bureaucrat::GradeTooLowException::what(void) const throw() { return ("Grade too low."); }
