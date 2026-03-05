/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:39:42 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/05 16:41:49 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "text_formatting.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;


// Static attr. init ============================================================


// Constructor & Destructor ====================================================
// ScalarConverter::ScalarConverter(void):
// 	{}
//
// ScalarConverter::ScalarConverter(const ScalarConverter &copy):
// 	{}
//
// ScalarConverter::~ScalarConverter(void) {}


// Operator Overloads ==========================================================
// ScalarConverter	&ScalarConverter::operator=(const ScalarConverter &assign)
// {
// 	if (this != &assign)
// 	{
// 		// xxxxxxxxxxxx
// 	}
// 	return (*this);
// }


// Member functions ============================================================
void	ScalarConverter::convert(const std::string &s)
{
	cout << s << endl;
	cout << YELLOW "char: \n" ;
	cout << RED "int: \n" ;
	cout << CYAN "float: \n" ;
	cout << MAGENTA "double: \n" RST ;
}

