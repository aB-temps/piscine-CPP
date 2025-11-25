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

#include 	<iostream>
#include 	"Fixed.hpp"

using		std::cout;
using		std::endl;

const int Fixed::_fract = 8;

Fixed::Fixed(void): _value(0)
{
	cout << "Default constructor called." << endl;
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

int		Fixed::getRawBits(void) const
{
	cout << "getRawBits member function called." << endl;
	return (this->_value);
}

void	Fixed::setRawBits(int const raw)
{
	cout << "setRawBits member function called." << endl;
	this->_value = raw;
}
