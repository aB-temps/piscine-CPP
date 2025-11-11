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

Fixed	&Fixed::operator=(const Fixed &assign)
{
	cout << "Copy assignment operator called." << endl;
	if (this != &assign)
	{
		this->_value = assign.getRawBits();
	}
	return (*this);
}

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
