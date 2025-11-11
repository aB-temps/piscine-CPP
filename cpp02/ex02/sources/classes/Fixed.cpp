/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:31:45 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/10 19:59:03 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cmath>
#include "Fixed.hpp"

using	std::cout;
using	std::endl;

const int Fixed::_fract = 8;

std::ostream	&operator<<(std::ostream &outstream, const Fixed &insert)
{
	outstream << insert.toFloat();
	return (outstream);
}

// Constructors/Destructors ===========================================================
Fixed::Fixed(void): _value(0)
{
	cout << "Default constructor called." << endl;
}

Fixed::Fixed(const int v): _value(v << Fixed::_fract)
{
	cout << "Int constructor called." << endl;
}

Fixed::Fixed(const float v): _value(roundf(v * (1 << Fixed::_fract)))
{
	cout << "Float constructor called." << endl;
}

Fixed::Fixed(const Fixed &copy)
{
	cout << "Copy constructor called." << endl;
	*this = copy;
}

Fixed::~Fixed(void)
{
	cout << "Destructor called." << endl;
}

// Operators ==========================================================================
Fixed	&Fixed::operator=(const Fixed &assign)
{
	cout << "Copy assignment operator called." << endl;
	if (this != &assign)
	{
		this->_value = assign.getRawBits();
	}
	return (*this);
}

// Inc/Dec operators =================================================================

Fixed	&Fixed::operator++(void)
{
	cout << "Pre-increment operator called." << endl;
	++this->_value;
	return(*this);
}

Fixed	Fixed::operator++(char)
{
	Fixed x(*this);

	cout << "Post-increment operator called." << endl;

	++this->_value;
	return (x);
}

Fixed	Fixed::operator+(const Fixed &other)
{
	cout << "Add operator called." << endl;
}

Fixed	Fixed::operator+=(const Fixed &other)
{
	cout << "Add-to operator called." << endl;
}

Fixed	&Fixed::operator--(void)
{
	cout << "Pre-decrement operator called." << endl;
	--this->_value;
	return(*this);
}

Fixed	Fixed::operator--(char)
{
	Fixed x(*this);
	cout << "Post-decrement operator called." << endl;

	--this->_value;
	return (x);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	cout << "Sub operator called." << endl;
}

Fixed	Fixed::operator-=(const Fixed &other)
{
	cout << "Sub-to operator called." << endl;
}

// Arithmetic operators ===============================================================
Fixed	Fixed::operator*(const Fixed &other)
{
	cout << "Product operator called." << endl;
}

Fixed	Fixed::operator*=(const Fixed &other)
{
	cout << "Product-to operator called." << endl;
}


Fixed	Fixed::operator/(const Fixed &other)
{
	cout << "Divide operator called." << endl;
}

Fixed	Fixed::operator/=(const Fixed &other)
{
	cout << "Divide-to operator called." << endl;
}

// Comparaison operators ==============================================================
bool	&Fixed::operator>(const Fixed &other)
{
	cout << "Superior operator called." << endl;
}

bool	&Fixed::operator<(const Fixed &other)
{
	cout << "Inferior operator called." << endl;
}

bool	&Fixed::operator>=(const Fixed &other)
{
	cout << "Superior or equal operator called." << endl;
}

bool	&Fixed::operator<=(const Fixed &other)
{
	cout << "Inferior or equal operator called." << endl;
}

bool	&Fixed::operator==(const Fixed &other)
{
	cout << "Equal operator called." << endl;
}

bool	&Fixed::operator!=(const Fixed &other)
{
	cout << "Different operator called." << endl;
}

// Member functions ===================================================================
int				Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called." << endl;
	return (this->_value);
}

void			Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called." << endl;
	this->_value = raw;
}

float			Fixed::toFloat(void) const
{
	return (static_cast<float>(this->_value) / static_cast<float>(1 << Fixed::_fract));
}

int				Fixed::toInt(void) const
{
	return (this->_value >> Fixed::_fract);
}
