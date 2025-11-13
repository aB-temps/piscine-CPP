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
Fixed::Fixed(void): _value(0) {}

Fixed::Fixed(const int v): _value(v << Fixed::_fract) {}

Fixed::Fixed(const float v): _value(roundf(v * (1 << Fixed::_fract))) {}

Fixed::Fixed(const Fixed &copy): _value(copy._value) {}

Fixed::~Fixed(void) {}

// Operators ==========================================================================
Fixed	&Fixed::operator=(const Fixed &assign)
{
	if (this != &assign)
	{
		this->_value = assign._value;
	}
	return (*this);
}

// Inc/Dec operators =================================================================

Fixed	&Fixed::operator++(void)
{
	++this->_value; //= (1 << Fixed::_fract);

	return(*this);
}

Fixed	Fixed::operator++(int)
{
	Fixed x(*this);

	this->operator++();

	return (x);
}

Fixed	Fixed::operator+(const Fixed &other)
{
	Fixed res;

	res._value = this->_value + other._value;

	return(res);
}

Fixed	Fixed::operator+=(const Fixed &other)
{
	this->_value += other._value;

	return(*this);
}

Fixed	&Fixed::operator--(void)
{
	--this->_value;// -= (1 << Fixed::_fract);

	return(*this);
}

Fixed	Fixed::operator--(int)
{
	Fixed x(*this);

	this->operator--();

	return (x);
}

Fixed	Fixed::operator-(const Fixed &other)
{
	Fixed res;

	res._value = this->_value - other._value;

	return(res);
}

Fixed	Fixed::operator-=(const Fixed &other)
{
	this->_value -= other._value;

	return(*this);
}

// Arithmetic operators ===============================================================
Fixed	Fixed::operator*(const Fixed &other)
{
	Fixed res;

	res._value = this->_value * other._value >> Fixed::_fract;

	return (res);
}

Fixed	Fixed::operator*=(const Fixed &other)
{
	*this = *this * other;

	return(*this);
}

Fixed	Fixed::operator/(const Fixed &other)
{
	Fixed res;

	res._value = this->_value / other._value << Fixed::_fract;

	return(res);
}

Fixed	Fixed::operator/=(const Fixed &other)
{
	*this = *this / other;

	return(*this);
}

// Comparaison operators ==============================================================
bool	Fixed::operator>(const Fixed &other)
{
	return (this->_value > other._value);
}

bool	Fixed::operator<(const Fixed &other)
{
	return (this->_value < other._value);
}

bool	Fixed::operator>=(const Fixed &other)
{
	return (this->_value >= other._value);
}

bool	Fixed::operator<=(const Fixed &other)
{
	return (this->_value <= other._value);
}

bool	Fixed::operator==(const Fixed &other)
{
	return (this->_value == other._value);
}

bool	Fixed::operator!=(const Fixed &other)
{
	return (this->_value != other._value);
}

// Member functions ===================================================================
Fixed			&Fixed::min(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() <= f2.getRawBits() ? const_cast<Fixed&>(f1) : const_cast<Fixed&>(f2));
}

Fixed			&Fixed::min(Fixed &f1, Fixed &f2)
{
	return (f1.getRawBits() <= f2.getRawBits() ? f1 : f2);
}

Fixed			&Fixed::max(const Fixed &f1, const Fixed &f2)
{
	return (f1.getRawBits() >= f2.getRawBits() ? const_cast<Fixed&>(f1) : const_cast<Fixed&>(f2));
}

Fixed			&Fixed::max(Fixed &f1, Fixed &f2)
{
	return (f1.getRawBits() >= f2.getRawBits() ? f1 : f2);
}


int				Fixed::getRawBits(void) const
{
	return (this->_value);
}

void			Fixed::setRawBits(int const raw)
{
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
