/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/10 15:03:22 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <exception>

#include "factory.tpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

using	std::cout;
using	std::endl;

Base	*generate(void)
{
	const t_builder	factory[DERIVED_COUNT] =
	{
		newBase<A>,
		newBase<B>,
		newBase<C>
	};
	return (factory[std::rand() % DERIVED_COUNT]());
}

void	identify(Base *p)
{
	if (!p)
	{
		cout << "null ptr" << endl;
		return ;
	}
	if (dynamic_cast<A *>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B *>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C *>(p))
		cout << "C" << endl;
}

void	identify(Base &p)
{
	try
	{
		Base &b = dynamic_cast<A &>(p);
		(void) b;
		cout << "A" << endl;
		return ;
	}
	catch (const std::exception &e) {}
	try
	{
		Base &b = dynamic_cast<B &>(p);
		(void) b;
		cout << "B" << endl;
		return ;
	}
	catch (const std::exception &e) {}
	try
	{
		Base &b = dynamic_cast<C &>(p);
		(void) b;
		cout << "C" << endl;
		return ;
	}
	catch (const std::exception &e) {}
}


int main(void)
{
	std::srand(time(0));

	Base	*b[ELEMENTS] = {0};

	for (int i = 0; i < ELEMENTS; ++i)
		b[i] = generate();

	for (int i = 0; i < ELEMENTS; ++i)
		identify(b[i]);

	cout << endl;

	for (int i = 0; i < ELEMENTS; ++i)
		identify(*b[i]);

	for (int i = 0; i < ELEMENTS; ++i)
		delete b[i];

	return (0);
}
