/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/16 16:30:04 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.tpp"

using	std::cout;
using	std::endl;

static void			sub1(char &v) { --v; }

static void			sad_display(const char &v)
{
	cout << "This is a sad value '" << v << "' isn't it?" << endl;
}

int	main(void)
{
	int			arr1[5] = { 2, 4, 91, 21, 7 };
	const int	carr1[3] = { 2, 4, 7 };

	char		arr2[4] = { 'b', 'f', 'x', 'm' };
	const char	carr2[6] = { 'b', '1', 'f', 'x', 'm', 'e' };

	display(arr1, 5);
	display(carr1, 3);
	display(arr2, 4);
	display(carr2, 6);

	cout << endl;

	iter(arr1, 5, add2<int>);
	iter(carr1, 3, funny_display<const int>);
	display(arr1, 5);


	cout << endl;

	iter(arr2, 4, sub1);
	iter(arr2, 4, sad_display);

	iter(carr2, 6, funny_display<const char>);
	iter(carr2, 6, sad_display);

	display(arr2, 4);

	return (0);
}
