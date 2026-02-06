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

namespace	bureaucratDefault
{
	const char defaultName = "Anonymous";
	const uint8_t defaultGrade = 1;
}

using	bureaucratDefault::defaultName;
using	bureaucratDefault::defaultGrade;

// Constructor & Destructor ====================================================
Bureaucrat::Bureaucrat(void): _name(defaultName), _grade(defaultGrade) {}

Bureaucrat::Bureaucrat(const Bureaucrat &copy): _name(copy.name) {}

Bureaucrat::Bureaucrat(const std::string &name, const uint8_t &grade): _name(name), _grade(grade) {}

Bureaucrat::~Bureaucrat(void) {}


// Operator Overloads ==========================================================
Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &assign) {}


// Getters
std::string	&Bureaucrat::getName(void) { return (this->_name); }
