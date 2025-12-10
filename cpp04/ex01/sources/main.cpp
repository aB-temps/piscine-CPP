/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 11:14:22 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include "Dog.hpp"

using	std::cout;
using	std::endl;

int main(void)
{
	cout << ">>> Copies:\n";
	cout << "> Constructors:" << endl;
	Cat		*c1 = new Cat();
	Cat		*c2 = new Cat(*c1);

	cout << "> Destructors:" << endl;
	delete c1;
	cout << "\n";
	delete c2;
	cout << endl;


	cout << ">>> Array:\n";
	cout << "> Constructors:" << endl;
	Animal	*animal_array[DEF_ARRAY_SIZE];
	for (int i = 0; i < DEF_ARRAY_SIZE; ++i)
	{
		if (i <= (DEF_ARRAY_SIZE >> 2))
			animal_array[i] = new Cat();
		else
			animal_array[i] = new Dog();
		cout << "\n";
	}
	
	cout << "> Destructors:" << endl;
	for (int i = 0; i < DEF_ARRAY_SIZE; ++i)
	{
		delete animal_array[i];
		cout << "\n";
	}
	cout << endl;

	return (0);
}
