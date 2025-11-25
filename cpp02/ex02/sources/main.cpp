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

#include	<iostream>
#include	"Fixed.hpp"

using		std::cout;
using		std::endl;

int main( void )
{
	Fixed a(5.5f);
	Fixed b(10.5f);
	// Fixed c(4.2f);
	// Fixed d(2.1f);
	// const Fixed e(4.2f);
	// const Fixed f(2.1f);
	//
	// cout << "a: " << a << endl;
	// cout << "a++: " << a++ << endl;
	// cout << "a: " << a << endl;
	// cout << "++a: " << ++a << endl;
	// cout << "a: " << a << endl << endl;
	//
	// cout << "b: " << b << endl;
	// cout << "b--: " << b-- << endl;
	// cout << "b: " << b << endl;
	// cout << "--b: " << --b << endl;
	// cout << "b: " << b << endl << endl;
	//
	// cout << "a: " << a << " b: " << b <<endl;
	// cout << "a + b: " << a + b << endl;
	// cout << "a - b: " << a - b << endl << endl;
	//
	// cout << "a: " << a << " b: " << b << endl;
	// a += b;
	// cout << "a += b: " << a << endl;
	// a -= b;
	// cout << "a -= b: " << a << endl << endl;
	//
	cout << "a: " << a << " b: " << b <<endl;
	cout << "a * b: " << a * b << endl;
	cout << "a / b: " << a / b << endl;
	cout << "a: " << a << " b: " << b <<endl << endl;
	//
	// cout << "a: " << a << " b: " << b <<endl;
	// a *= b;
	// cout << "a *= b: " << a << endl << endl;
	//
	// cout << "c: " << c << " d: " << d <<endl;
	// c /= d;
	// cout << "c /= d: " << c << endl;
	// cout << "c: " << c << " d: " << d <<endl << endl;

	// cout << "a: " << a << " b: " << b <<endl;
	// cout << "a < b: " << (a < b) << endl;
	// cout << "a > b: " << (a > b) << endl;
	// cout << "a <= b: " << (a <= b) << endl;
	// cout << "a >= b: " << (a >= b) << endl;
	// cout << "a == b: " << (a == b) << endl;
	// cout << "a != b: " << (a != b) << endl << endl;

	// cout << "c: " << c << " d: " << d <<endl;
	// cout << "min(c,d): " << Fixed::min(c, d) << endl;
	// cout << "max(c,d): " << Fixed::max(c, d) << endl << endl;
	// cout << "e: " << e << " f: " << f <<endl;
	// cout << "const min(e,f): " << Fixed::min(e, f) << endl;
	// cout << "const max(e,f): " << Fixed::max(e, f) << endl;
	//
	// Fixed a;
	// Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	//
	// std::cout << a << std::endl;
	// std::cout << ++a << std::endl;
	// std::cout << a << std::endl;
	// std::cout << a++ << std::endl;
	// std::cout << a << std::endl;
	// std::cout << b << std::endl;
	//
	// std::cout << Fixed::max( a, b ) << std::endl;

	return (0);
}
