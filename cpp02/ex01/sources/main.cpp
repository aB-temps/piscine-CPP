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

#include 	<iostream>
#include 	"Fixed.hpp"

using		std::cout;
using		std::endl;

int main( void )
{
	Fixed a;
	Fixed const b( 10 );
	Fixed const c( 42.51f );
	Fixed const d( b );

	a = Fixed( 1234.4321f );

	cout << "a is " << a << "\n"
 		 << "b is " << b << "\n"
 		 << "c is " << c << "\n"
		 << "d is " << d << endl;

	cout << "a is " << a.toInt() << " as integer" << "\n"
	 	 << "b is " << b.toInt() << " as integer" << "\n"
	 	 << "c is " << c.toInt() << " as integer" << "\n"
	 	 << "d is " << d.toInt() << " as integer" << endl;

	return (0);
}
