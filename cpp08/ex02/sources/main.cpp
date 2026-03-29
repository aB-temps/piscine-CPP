/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:26:17 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/21 17:03:33 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

using	std::cout;
using	std::endl;

int main(void)
{
	cout << "STACK >>>>>>>>>>>>" << endl;
	MutantStack<int> mstack;

	cout << "SIZE(before pushes): " << mstack.size() << endl;
	mstack.push(5);
	mstack.push(17);
	mstack.push(3);
	mstack.push(51);
	mstack.push(737);
	mstack.push(880);
	cout << "SIZE(after pushes): " << mstack.size() << endl;

	MutantStack<int>::iterator m_it = mstack.begin();
	MutantStack<int>::iterator m_ite = mstack.end();

	while (m_it != m_ite)
	{
		cout << *m_it << endl;
		++m_it;
	}


	cout << "\nLIST >>>>>>>>>>>>" << endl;
	std::list<int> list;

	cout << "SIZE(before push_backs): " << list.size() << endl;
	list.push_back(5);
	list.push_back(17);
	list.push_back(3);
	list.push_back(51);
	list.push_back(737);
	list.push_back(880);
	cout << "SIZE(after push_backs): " << list.size() << endl;

	std::list<int>::iterator l_it = list.begin();
	std::list<int>::iterator l_ite = list.end();

	++l_it;
	--l_it;

	while (l_it != l_ite)
	{
		cout << *l_it << endl;
		++l_it;
	}

	return 0;
}
