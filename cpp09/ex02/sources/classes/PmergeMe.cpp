/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:08:16 by abetemps          #+#    #+#             */
/*   Updated: 2026/08/12 20:42:49 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <algorithm>
# include <cmath>
# include <cctype>
# include "PmergeMe.hpp"

using	std::cout;
using	std::cerr;
using	std::endl;

// private cannonical form members =============================================
PmergeMe::PmergeMe(void) {}

PmergeMe::~PmergeMe(void) {}

PmergeMe::PmergeMe(const PmergeMe &cpy) { (void) cpy; }

PmergeMe	&PmergeMe::operator=(const PmergeMe &assign) { (void) assign; return (*this); }

// Utils  ======================================================================
void	PmergeMe::_swap(uint32_t &x, uint32_t &y)
{
	x ^= y;
	y ^= x;
	x ^= y;
}

bool	PmergeMe::_isOnlyNum(const std::string &str)
{
	for (size_t i = 0; i < str.length(); ++i)
	{
		if (!std::isdigit(str[i]) && !std::iswspace(str[i]))
			return (false);
	}
	return (true);
}

std::ostream	&operator<<(std::ostream &out, const std::vector<uint32_t> &vec)
{
	for (size_t i = 0; i < vec.size(); ++i)
	{
		out << vec[i] << (i < vec.size() - 1 ? " " : "");
	}
	return (out);
}

std::ostream	&operator<<(std::ostream &out, const std::deque<uint32_t> &deq)
{
	for (std::deque<uint32_t>::const_iterator it = deq.begin(); it < deq.end(); ++it)
	{
		out << *it << (it < deq.end() - 1 ? " " : "");
	}
	return (out);
}

// Ford-Johnsonn  ==============================================================
void	PmergeMe::_binaryInsert(std::deque<uint32_t> &base, uint32_t element)
{
	unsigned int minI = 0;
	unsigned int maxI = base.size() - 1;
	unsigned int midI;

	while (minI < maxI)
	{
		midI = minI + (maxI / 2);

		if (element > base[midI])
			minI = midI + 1;
		else
			maxI = midI - 1;

	}
	base.insert(base.begin() + minI, element);
}

void	PmergeMe::sort(std::deque<uint32_t> &base)
{
	static unsigned int u = 0;
	cout << "-----------------\nTurn no " << u++ + 1 << ":\n";
	std::deque<uint32_t>::iterator it = base.begin();
	std::deque<uint32_t> main;
	std::deque<uint32_t> pend;

	for (it = base.begin(); it < base.end() - (base.size() % 2); it += 2)
	{
		// make a swap n by n
		cout << "[" << *it << " " << *(it + 1) << "] => ";
		if (*it > *(it + 1))
			PmergeMe::_swap(*it, *(it + 1));

		main.push_back(*(it + 1));
		pend.push_back(*it);

		cout << "[" << *it << " " << *(it + 1) << "]\n";
	}
	cout << "\nBase: " <<  base << endl;
	cout << "Main: " <<  main << endl;
	cout << "Pend: " <<  pend << endl;

	cout << "-----------------\n";
	if (main.size() > 1)
		PmergeMe::sort(main);
	PmergeMe::_binaryInsert(main, pend[0]);
	cout << main << endl;

	base = main;
}

// void	PmergeMe::sort(std::vector<uint32_t> &base)
// {
// 	(void) base;
// }

