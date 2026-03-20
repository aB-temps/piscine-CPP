/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/19 13:32:34 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/19 17:22:43 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>

#include <iostream>

#include <vector>
#include <list>

#include "easyfind.hpp"

#define VAL_RANGE	25
#define NB_ELEM		5

using	std::cout;
using	std::endl;

template		<typename T>
static void		print_ctn(const T &ctn)
{
	cout	<< "for container of size " << ctn.size()
			<< " at address " << &ctn
			<< ":" << endl;
	for (typename T::const_iterator i = ctn.begin(); i != ctn.end(); ++i)
		cout	<< &i
				<< ":\n- [" << &i 
				<< "] " << *i
				<< '\n'
				<< endl;
	cout << endl;
}

int	main(void)
{
	std::srand(time(0));

	std::vector<int>	v;
	std::list<int>		l;

	for (int i = 0; i < NB_ELEM; ++i)
	{
		v.push_back(rand() % VAL_RANGE);
		l.push_back(rand() % VAL_RANGE);
	}
	print_ctn(v);
	print_ctn(l);


	const int	to_find = rand() % VAL_RANGE;
	cout << "Searching value " << to_find << "..." << endl;

	std::vector<int>::const_iterator		it_vector = easyfind(v, to_find);
	std::list<int>::const_iterator			it_list = easyfind(l, to_find);

	if (it_vector == v.end())
		cout << "[VECTOR]	Value not found." << endl;
	else
		cout << "[VECTOR]	Found value!" << endl;
	if (it_list == l.end())
		cout << "[LIST]		Value not found." << endl;
	else                	
		cout << "[LIST]		Found value!" << endl;

    return (0);
}
