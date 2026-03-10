/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/10 14:30:33 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include <cstdlib>
#include <iostream>

#include "factory.tpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

using	std::cout;
using	std::endl;

Base	*generate(void)
{
	const t_builder	factory[3] =
	{
		newBase<A>,
		newBase<B>,
		newBase<C>
	};
	return (factory[std::rand() % 3]());
}

void	identify(Base *p)
{
	if (dynamic_cast<A *>(p))
		cout << "A" << endl;
	else if (dynamic_cast<B *>(p))
		cout << "B" << endl;
	else if (dynamic_cast<C *>(p))
		cout << "C" << endl;
}

void	identify(Base &p)
{
	identify(&p);
}


int main(void)
{
	std::srand(time(0));

	Base	*b[3] = {0};

	for (int i = 0; i < 3; ++i)
		b[i] = generate();

	for (int i = 0; i < 3; ++i)
		identify(b[i]);

	cout << endl;

	for (int i = 0; i < 3; ++i)
		identify(*b[i]);


	return (0);
}
