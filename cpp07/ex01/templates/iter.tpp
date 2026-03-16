/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:29:22 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/16 16:31:23 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ITER_TPP__
# define	__ITER_TPP__

#include <cstddef>
#include <iostream>

using	std::cout;
using	std::endl;

template	<typename T>
void		iter(T *array, const size_t length, void (func)(T &))
{
	for (size_t i = 0; i < length; ++i)
		func(array[i]);
}

// util template function
template	<typename T>
void		display(T *array, const size_t length)
{
	cout << "array of length " << length << ":" << endl;
	for (size_t i = 0; i < length; ++i)
		cout << "[" << i << "] -> " <<  array[i] << endl;
}

// test template functions
template	<typename T>
void		add2(T &a)
{
	a += 2;
}

template	<typename T>
void		funny_display(const T &a)
{
	cout << "This is a fun value '" << a << "' isn't it?" << endl;
}
#endif
