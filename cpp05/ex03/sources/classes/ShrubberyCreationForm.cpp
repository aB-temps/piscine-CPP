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

#include <fstream>
#include "Bureaucrat.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================
const char		*ShrubberyCreationForm::_defaultName = "ShrubberyCreationForm";
const t_uint8	ShrubberyCreationForm::_defaultSignGrade = 145;
const t_uint8	ShrubberyCreationForm::_defaultExecGrade = 137;
const char		*ShrubberyCreationForm::_defaultTree =
"              * *    \n"
"           *    *  *\n"
"      *  *    *     *  *\n"
"     *     *    *  *    *\n"
" * *   *    *    *    *   *\n"
" *     *  *    * * .#  *   *\n"
" *   *     * #.  .# *   *\n"
"  *     \"#.  #: #\" * *    *\n"
" *   * * \"#. ##\"       *\n"
"   *       \"###\n"
"             \"##\n"
"              ##.\n"
"              .##:\n"
"              :###\n"
"              ;###\n"
"            ,####.\n"
"/\\/\\/\\/\\/.######.\\/\\/\\/\\/\\\\\n";


// Constructor & Destructor ====================================================
ShrubberyCreationForm::ShrubberyCreationForm(const char *target):
	AForm(ShrubberyCreationForm::_defaultName, target, ShrubberyCreationForm::_defaultSignGrade, ShrubberyCreationForm::_defaultExecGrade) {}

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
void	ShrubberyCreationForm::_executeSelf(void) const
{
	std::string	ofname(this->getTarget() + "_shrubbery");
	try
	{
		std::ofstream	outfile;
		
		outfile.exceptions(std::ios::eofbit | std::ios::failbit | std::ios::badbit);
		outfile.open(ofname.c_str());

		outfile << ShrubberyCreationForm::_defaultTree;
	}
	catch (const std::ios::failure &e)
	{
		throw;
	}
}
