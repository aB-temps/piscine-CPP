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

// Namespaces ==================================================================
namespace	Bureaucrat::ns_BureaucratSettings
{
	const char		defaultName[] = "Anonymous";
	const t_uint8	minGrade = 150;
	const t_uint8 	maxGrade = 1;
	const t_uint8 	defaultGrade = minGrade;
};

// Using =======================================================================
using	ns_BureaucratSettings::defaultName;
using	ns_BureaucratSettings::minGrade;
using	ns_BureaucratSettings::maxGrade;
using	ns_BureaucratSettings::defaultGrade;

using	std::cout;
using	std::endl;

// Constructor & Destructor ====================================================
Bureaucrat::Bureaucrat(void):
	_name(defaultName), 
	_grade(defaultGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy):
	_name(copy._name),
	_grade(copy._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, const t_uint8 &grade):
	_name(name),
	_grade(grade),
{
	if (grade < maxGrade)
		throw (Bureaucrat::GradeTooHighException);
	else if (grade > minGrade)
		throw (Bureaucrat::GradeTooLowException);
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
	outstream	<< "NAME: " << insert.getName()
				<< "\nGRADE: " << insert.getGrade()
				<< endl;

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


// Getters
const std::string	&Bureaucrat::getName(void) const { return (this->_name); }

const t_uint8		&Bureaucrat::getGrade(void) const { return (this->_grade); }
