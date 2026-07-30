/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:31:24 by abetemps          #+#    #+#             */
/*   Updated: 2026/07/30 09:05:53 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stack>
# include <cctype>
# include "RPN.hpp"

using	std::cout;
using	std::cerr;
using	std::endl;

// Constructors/Destructor -----------------------------------------------------
RPN::RPN(void)
{}

RPN::RPN(const RPN &cpy)
{
	(void) cpy;
}

RPN::~RPN(void)
{}

// Ops overloading -------------------------------------------------------------
RPN	&RPN::operator=(const RPN &assign)
{
	(void) assign;

	return (*this);
}

// Member Function -------------------------------------------------------------
float	RPN::computeExpr(const char *input)
{
	std::stack<int>	operands;

	for (size_t i = 0; input[i]; ++i) 
	{
		if (std::isspace(input[i]))
			continue;
		else if (std::isdigit(input[i]))
		{
			operands.push(input[i] - '0');
		}
		else if (RPN::_isOperator(input[i]))
		{
			if (operands.size() < 2)
				throw (std::runtime_error("invalid expression"));

			const float	o2 = operands.top();
			operands.pop();

			const float	o1 = operands.top();
			operands.pop();

			operands.push(RPN::_compute(o1, o2, input[i]));
		}
	}
	
	return (operands.top());
}

float	RPN::_compute(const float o1, const float o2, const char op)
{
	switch (op)
	{
		case ('+'):
			return (o1 + o2);
		case ('-'):
			return (o1 - o2);
		case ('/'):
			if (!o2)
				throw (std::runtime_error("division by 0"));
			return (o1 / o2);
		case ('*'):
			return (o1 * o2);
	}
	return (0);
}

bool	RPN::_isOperator(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '*');
}
