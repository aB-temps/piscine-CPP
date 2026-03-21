/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2026/02/06 18:39:27 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include "Span.hpp"

using	std::cout;
using	std::endl;

int main(void)
{
	srand(time(0));

	const Span c_sp(5);
	Span sp(5);

	try
	{
		sp.addNumber(2);
		sp.addNumber(9);
		sp.addNumber(4);
		// sp.addRange(999999);	// ADD_RANGE out of range
		cout << "Shortest span: " << sp.shortestSpan() << endl;
		cout << "Longest span: " << sp.longestSpan() << endl;

		Span sp2(sp);

		// cout << sp[-1]; // ACCESS out of range
		cout << sp ; //<< endl << sp2 << endl;
	}
	catch (const std::out_of_range &e)
	{
		cout << e.what() << endl;
		return (1);
	}

	return (0);
}
