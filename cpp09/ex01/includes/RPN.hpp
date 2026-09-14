/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 12:31:38 by abetemps          #+#    #+#             */
/*   Updated: 2026/07/30 06:26:25 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__RPN_HPP__
# define	__RPN_HPP__

# include <iostream>

class	RPN
{
	public:
		static int	computeExpr(const char *input);

	private:
		RPN(void);
		RPN(const RPN &cpy);
		~RPN(void);
		RPN	&operator=(const RPN &assign);

		static bool		_isOperator(const char c);
		static int		_compute(int o1, int o2, char op);
};

#endif
