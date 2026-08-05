/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:29:22 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/17 16:55:25 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ITER_HPP__
# define	__ITER_HPP__

#include <iostream>

using	std::cout;
using	std::endl;

template	<typename T, typename F>
void		iter(T *array, const size_t length, F func)
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

// util template function
template	<typename T>
void		display(const T *array, const size_t length)
{
	cout << "array of length " << length << ":" << endl;
	for (size_t i = 0; i < length; ++i)
		cout << "[" << i << "] -> " <<  array[i] << endl;
}

// test template functions
template	<typename T>
void		add2(T &a) { a += 2; }

void		add3(int &a) { a += 3; }

template	<typename T>
void		funny_display(const T &a)
{
	cout << "This is a fun value '" << a << "' isn't it?" << endl;
}

void		funny_display2(const int &a)
{
	cout << "This is a fun int '" << a << "' isn't it?" << endl;
}

#endif
