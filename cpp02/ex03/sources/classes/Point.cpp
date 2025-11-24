/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/24 13:51:42 by abetemps          #+#    #+#             */
/*   Updated: 2025/11/24 17:53:40 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

// Constructor/Destructors ==============================================================
Point::Point(void): _x(0), _y(0) {}

Point::Point(const float x, const float y): _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(const Point &copy): _x(copy.getX()), _y(copy.getY()) {}

Point::~Point(void) {}

// Overloaded operators =================================================================
Point			&Point::operator=(const Point &assign)
{
	if (this != &assign)
	{
		static_cast<Fixed>(this->_x) = static_cast<Fixed>(assign._x);
		static_cast<Fixed>(this->_y) = static_cast<Fixed>(assign._y);
	}
	return (*this);
}

// Getters ==============================================================================
Fixed		Point::getX(void) const
{
	return (this->_x);
}

Fixed		Point::getY(void) const
{
	return (this->_y);
}
