/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/06 18:39:42 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/20 21:26:33 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <stdexcept>
#include <sstream>

#include "Span.hpp"

#define MAX_VAL	256

#define ADD_NUM		0
#define ADD_RANGE	1
#define ACCESS		2

// Using =======================================================================
using	std::cout;
using	std::endl;


// Constructor & Destructor ====================================================
Span::Span(const unsigned int &capacity):
	_array(std::vector<int>(0)),
	_capacity(capacity) {}

Span::Span(const Span &copy):
	_array(std::vector<int>(0)),
	_capacity(copy._capacity)
{
	this->_array = copy._array;
}

Span::~Span(void) {}

// Operator Overloads ==========================================================
Span	&Span::operator=(const Span &assign)
{
	if (this != &assign)
	{
		this->_capacity = assign._capacity;
		this->_array = assign._array;
	}
	return (*this);
}

int			&Span::operator[](const unsigned int &i)
{
	if (i >= this->_capacity || i >= this->_array.size())
		outOfRange(i, ACCESS);
	return (this->_array[i]);
}

const int	&Span::operator[](const unsigned int &i) const
{
	if (i >= this->_capacity || i >= this->_array.size())
		outOfRange(i, ACCESS);
	return (this->_array[i]);
}

// Getters =====================================================================
unsigned int	Span::getSize(void) const
{
	return (this->_array.size());
}


// Member functions ============================================================
std::ostream	&operator<<(std::ostream &out, const Span &sp)
{
	out << "Span of size " << sp.getSize() << ":\n";
	for (size_t i = 0; i < sp.getSize(); ++i)
		out	<< "[" << i << "] "
				<< sp[i] << endl;
	return (out);

}

void		Span::outOfRange(const unsigned int &i, const unsigned char mode) const
{
	std::stringstream	i_ss;
	std::string			i_str;

	i_ss << i;
	i_ss >> i_str;
	switch (mode)
	{
		case(ADD_RANGE):
			throw (std::out_of_range("Out of range error trying to store " + i_str + " new elements."));
			break;
		case(ADD_NUM):
			throw (std::out_of_range("Out of range error trying to store " + i_str));
			break;
		case(ACCESS):
			throw (std::out_of_range("Out of range error trying to access array at index " + i_str));
			break;
	}
}

void	Span::addRange(const unsigned int &r)
{
	if (this->_array.size() + r <= this->_capacity)
	{
		this->_array.insert(this->_array.end(), r, rand());
	}
	else
		outOfRange(r, ADD_RANGE);
}

void	Span::addRange(const std::vector<int>::iterator &begin, const std::vector<int>::iterator &end)
{
	const unsigned int dist = std::distance(begin, end);
	if (this->_array.size() + dist <= this->_capacity)
	{
		this->_array.insert(this->_array.end(), begin, end);
	}
	else
		outOfRange(dist, ADD_RANGE);
}

void	Span::addNumber(const int &n)
{
	if (this->_array.size() < this->_capacity)
	{
		this->_array.push_back(n);
	}
	else
		outOfRange(n, ADD_NUM);
}

int	Span::longestSpan(void) const
{
	const std::vector<int>::const_iterator	begin = this->_array.begin();
	const std::vector<int>::const_iterator	end = this->_array.end();

	const int								min = *std::min_element(begin, end);
	const int								max = *std::max_element(begin, end);

	return (max - min);
}

int	Span::shortestSpan(void) const
{
	std::vector<int> tmp = this->_array;

	std::sort(tmp.begin(), tmp.end());

	std::adjacent_difference(tmp.begin(), tmp.end(), tmp.begin());

	return (*std::min_element(tmp.begin(), tmp.end()));
}
