/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/10 19:32:09 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "bsp.hpp"

using	std::cout;
using	std::endl;

int	main(void)
{
	const Point A(4, 8);
	const Point B(10, 2);
	const Point C(1, 4);

	const Point Pa(6, 4);		// OK
	const Point Pb(9.0, 8.5);	// KO
	const Point Pc(4, 2);		// KO
	const Point Pd(1, 6);		// KO
	const Point Pe(8.5f, 3.2f); // OK
	const Point Pf(3, 5);		// OK

	cout << ( bsp(A, B, C, Pa) ? "true\n" : "false\n" ) << endl;
	cout << ( bsp(A, B, C, Pb) ? "true\n" : "false\n" ) << endl;
	cout << ( bsp(A, B, C, Pc) ? "true\n" : "false\n" ) << endl;
	cout << ( bsp(A, B, C, Pd) ? "true\n" : "false\n" ) << endl;
	cout << ( bsp(A, B, C, Pe) ? "true\n" : "false\n" ) << endl;
	cout << ( bsp(A, B, C, Pf) ? "true\n" : "false\n" ) << endl;

	return (0);
}
