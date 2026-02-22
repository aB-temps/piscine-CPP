/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   GradeException.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 15:11:50 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/07 18:11:07 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "GradeException.hpp"

// Static attr. init ===========================================================
const std::string	GradeException::_excptType = "GradeException";

// Constructor & Destructor ====================================================
GradeException::GradeException(void) {}

GradeException::~GradeException(void) throw() {}

GradeException::GradeException(const char *targetType, const char *msg):
	_targetType(std::string(targetType)),
	_errMsg(std::string(msg))
{
	this->_whatMsg = this->_targetType + "(" + GradeException::_excptType + "): " + this->_errMsg + ".";
}

// what() overload =============================================================
const char	*GradeException::what(void) const throw()
{
	return (this->_whatMsg.c_str());
}
