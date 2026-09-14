/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:31:24 by abetemps          #+#    #+#             */
/*   Updated: 2026/07/30 09:10:08 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stack>
# include <cctype>
# include "RPN.hpp"

using	std::cout;
using	std::cerr;
using	std::endl;

// Member Function -------------------------------------------------------------
int	RPN::computeExpr(const char *input)
{
	std::stack<int>	operands;

	for (size_t i = 0; input[i]; ++i) 
	{
		if (std::isspace(input[i]))
			continue;
		else if (std::isdigit(input[i]))
			operands.push(input[i] - '0');
		else if (RPN::_isOperator(input[i]))
		{
			if (operands.size() < 2)
				throw (std::runtime_error("invalid expression"));

			const int	o2 = operands.top();
			operands.pop();

			const int	o1 = operands.top();
			operands.pop();

			operands.push(RPN::_compute(o1, o2, input[i]));
		}
		else
			throw (std::runtime_error("invalid expression"));
	}
	if (operands.size() != 1)
		throw (std::runtime_error("invalid expression"));
	return (operands.top());
}

int	RPN::_compute(int o1, int o2, char op)
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
