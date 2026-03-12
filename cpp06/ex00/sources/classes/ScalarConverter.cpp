/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:39:42 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/05 17:46:12 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <limits.h>

#include "ScalarConverter.hpp"
#include "text_formatting.hpp"

// Using =======================================================================
using	std::cout;
using	std::endl;

// Constructor & Destructor ====================================================
ScalarConverter::ScalarConverter(void) {}

// Member functions ============================================================
bool	strisalpha(const std::string &s)
{
	for (int i = 0; s[i]; ++i)
	{
		if (!std::isalpha(s[i]))
			return (false);
	}
	return (true);
}

bool	strisdigit(const std::string &s)
{
	for (int i = 0; s[i]; ++i)
	{
		if (!std::isdigit(s[i]))
			return (false);
	}
	return (true);
}

unsigned char	ScalarConverter::_getType(const std::string &s)
{
	if (s.length() > 1 && strisalpha(s))
		return (UNKNOWN);
	if (strisdigit(s))
		return (INT);
	if (s.length() == 1 && s[0] < 127)
		return (CHAR);
	return (FLOAT);
}

void			ScalarConverter::_displayChar(const std::string &s, const unsigned char type)
{
	int val = (type == CHAR ? s[0] : std::atoi(s.c_str()));
	if (val > 127 || type == UNKNOWN)
		cout << "impossible";
	else if (val < 31)
		cout << "non displayable";
	else
	{
		cout	<< '\''
			<< static_cast<unsigned char>(val)
			<< '\'';
	}
}

void			ScalarConverter::_displayInt(const std::string &s, const unsigned char type)
{
	double val = (type == CHAR ? s[0] : std::atoi(s.c_str()));
	if (val > INT_MAX || val < INT_MIN || type == UNKNOWN)
		cout << "impossible";
	else
		cout << static_cast<int>(val);
}

void			ScalarConverter::_displayFloat(const std::string &s, const unsigned char type)
{
	(void) type;

	char	*end = NULL;
	float	val = static_cast<float>(strtod(s.c_str(), &end));

	if (&s[0] == end)
	{
		cout << "impossible";
		return ;
	}
	else if (type == FLOAT)
	{
		cout << val << (s.find('.') == s.length() ? "." : "");
	}
	else
		cout << val << (type == UNKNOWN ? "" : ".0");
	cout << "f";
}

void			ScalarConverter::_displayDouble(const std::string &s, const unsigned char type)
{
	(void) type;

	char	*end = NULL;
	float	val = static_cast<float>(strtod(s.c_str(), &end));

	if (&s[0] == end)
		cout << "impossible";
	else if (type == FLOAT)
		cout << val;
	else
		cout << val << (type == UNKNOWN ? "" : ".0");
}

void			ScalarConverter::convert(const std::string &s)
{
	void	(*f[TYPES])(const std::string &s, const unsigned char type) =
	{
		&ScalarConverter::_displayChar,
		&ScalarConverter::_displayInt,
		&ScalarConverter::_displayFloat,
		&ScalarConverter::_displayDouble
	};
	const char	*_types[TYPES] =
	{
		YELLOW "char" RST,
		CYAN "int" RST,
		MAGENTA "float" RST,
		RED "double" RST,
	};

	const unsigned char type = ScalarConverter::_getType(s);
	for (unsigned char i = 0; i < TYPES; ++i)
	{
		cout	<< _types[i]
				<< ": " BOLD;
		f[i](s, type);
		cout << RST << endl;
	}
}

