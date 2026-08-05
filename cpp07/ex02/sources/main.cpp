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

#include <ctime>
#include <cstdlib>
#include "Array.hpp"

#define MAX_VAL 10

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (unsigned int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand() % 15;
        numbers[i] = value;
        mirror[i] = value;
    }
	std::cout << numbers << std::endl;
 
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

	Array<int>  a;

	a = numbers;

	const Array<int>  b(a);


	std::cout << "a[2]: " << a[2] << std::endl;
	std::cout << "b[2]: " << b[2] << std::endl;

    for (unsigned int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cout << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::out_of_range& e)
    {
        std::cerr << e.what() << '\n';
    }

    delete [] mirror;
    return 0;
}
