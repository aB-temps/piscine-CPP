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
#include <stack>
#include <limits.h>

#include "Span.hpp"

#define SIZE 10

using	std::cout;
using	std::endl;

int main(void)
{
	srand(time(0));

	const Span			c_sp(5);
	Span				sp(SIZE);

	std::vector<int>	filler;
	
	try
	{
		for (unsigned int i = 0; i < SIZE; ++i)
			filler.push_back(rand() % MAX_VAL);

		sp.addRange(filler.begin(), filler.end());

		// sp.addNumber(4);	// ADD_RANGE out of range
		// sp.addRange(999999);	// ADD_RANGE out of range
		cout << "Shortest span: " << sp.shortestSpan() << endl;
		cout << "Longest span: " << sp.longestSpan() << endl;

		Span sp2(sp);

		cout << sp << endl;
		// cout << sp[INT_MAX]; // ACCESS out of range
	}
	catch (const std::out_of_range &e)
	{
		cout << e.what() << endl;
		return (2);
	}
	catch (const std::exception &e)
	{
		cout << e.what() << endl;
		return (1);
	}

	return (0);
}
