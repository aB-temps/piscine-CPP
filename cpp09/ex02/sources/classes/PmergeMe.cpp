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
void	PmergeMe::_binaryInsert(std::deque<uint32_t> &base, const uint32_t element, uint32_t maxI)
{
	unsigned int minI = 0;
	// unsigned int maxI = base.size() - 1; // 
	unsigned int midI;
	cout << "\nminI: " <<  minI << endl;
	cout << "maxI: " <<  maxI << endl << endl;

	while (minI < maxI)
	{

		midI = minI + ((maxI - minI) >> 1);
		// cout << "- midI: " <<  midI << " ==> " << element << " > " << base[midI] << " - " << (element > base[midI] ? "true" : "false");
		if (element > base[midI])
			minI = midI + 1;
		else
			maxI = midI;
		// cout << "\nminI: " <<  minI << endl;
		// cout << "maxI: " <<  maxI << endl << endl;
	}
	// cout << "-> index: " << minI << endl;
	base.insert(base.begin() + minI, element);
}

const std::vector<uint32_t>	PmergeMe::_buildJSSeq(const uint32_t max)
{
	std::vector<uint32_t> initalSeq;
	std::vector<uint32_t> computedSeq;

	uint32_t	prev = 0;
	uint32_t	val = 1;
	uint32_t	tmp;

	while(val <= max)
	{
		tmp = prev << 1;
		prev = val;
		val += tmp;
		if (val > 1)
			initalSeq.push_back(val);
	}
	cout << "[init] Sequence is: " << initalSeq << endl;

	for (uint32_t i = 0; i < initalSeq.size(); ++i)
	{
		computedSeq.push_back(initalSeq[i]);
		for (unsigned j = computedSeq[i] - 1; j >= 1; --j)
			computedSeq.push_back(j);
	}

	cout << "[final] Sequence is: " << computedSeq << endl;
	return (computedSeq);
}

// void	PmergeMe::sort(std::deque<uint32_t> &base)
// {
// 	static unsigned int u = 0;
// 	cout << "-----------------\nTurn no " << u++ + 1 << ":\n";
// 	std::deque<uint32_t>::iterator it = base.begin();
// 	std::deque<uint32_t> main;
// 	std::deque<uint32_t> pend;
// 	// static std::deque<uint32_t> &last_pend = pend;
//
// 	for (it = base.begin(); it < base.end() - (base.size() % 2); it += 2)
// 	{
// 		// make a swap n by n
// 		cout << "[" << *it << " " << *(it + 1) << "] => ";
// 		if (*it > *(it + 1))
// 		{
// 			PmergeMe::_swap(*it, *(it + 1));
// 			// if (u > 1)
// 			// 	PmergeMe::_swap(last_pend[it - base.begin()], last_pend[it - base.begin() + 1]);
// 		}
//
// 		main.push_back(*(it + 1));
// 		pend.push_back(*it);
//
// 		cout << "[" << *it << " " << *(it + 1) << "]\n";
// 	}
// 	if (it != base.end()) 
// 		pend.push_back(*it);
// 	cout << "\nBase: " <<  base << endl;
// 	cout << "Main: " <<  main << endl;
// 	cout << "Pend: " <<  pend << endl;
// 	// if (u > 1)
// 	// 	cout << "Last Pend: " <<  last_pend << endl;
//
// 	cout << "-----------------\n";
// 	if (main.size() > 1)
// 	{
// 		// last_pend = pend;
// 		PmergeMe::sort(main);
// 	}
//
// 	cout << "\n=================\n";
// 	// if (pend.size() > 1)
// 	// 	pend = last_pend;
// 	cout << "*Base: " <<  base << endl;
// 	cout << "*Main: " <<  main << endl;
// 	cout << "*Pend: " <<  pend << endl << endl;
// 	// cout << "*Last Pend: " <<  last_pend << endl << endl;
// 	const std::vector<uint32_t> JSSeq = PmergeMe::_buildJSSeq(pend.size() - 1);
//
// 	for (unsigned int i = 0; i < pend.size(); ++i)
// 	{
// 		uint32_t	maxI = i + 1;
// 		cout << "[" << i << "]inserting: " << pend[i] << endl;
//
// 		if (i < main.size() - i)
// 			cout << "was paired with : " << base[(i << 1) + 1] << endl;
// 		else
// 		{
// 			cout << "was not paired" << endl;
// 			maxI = main.size() - 1;
// 		}
// 		// pend[i] = the element to binary insert, has to be the JacobStahl'th value in the pend chain
// 		PmergeMe::_binaryInsert(main, pend[i], maxI);
// 		cout << "new main: " <<  main << endl;
// 		cout << "--------------\n";
// 	}
//
// 	cout << "-> Main: " << main << endl;
// 	base = main;
// }

void	displayElem(std::deque<uint32_t>::iterator it, const uint32_t size)
{
	cout << BOLD "[" RST GREEN;
	for (uint32_t i = 0; i < size; ++i)
		cout << *(it + i) << (i == size - 1 ? "" : " ");
	cout << RST BOLD "] " RST;
}

void	PmergeMe::_recursivePairSorting(std::deque<uint32_t> &base)
{
	static uint32_t u = 0;
	cout << "-----------------\nTurn no " BLUE BOLD << u++ + 1 << RST ":\n";
	std::deque<uint32_t>::iterator it = base.begin();

	uint32_t groupSize = std::pow(2, u);
	cout << "Element groups of size: " BOLD YELLOW <<  groupSize << RST << endl;
	for (it = base.begin(); it <= base.end() - groupSize; it += groupSize)
	{
		displayElem(it, groupSize);
		// if (*it + groupSize)
	}
	for (; it < base.end(); ++it)
		cout << RED << *it << " ";
	cout << RST << endl;


	if (u < 4)
		PmergeMe::_recursivePairSorting(base);

}

void	PmergeMe::sort(std::deque<uint32_t> &base)
{
	cout << endl << endl;
	cout << BOLD UNDL BLUE "Step 1:\n" RST;
	PmergeMe::_recursivePairSorting(base);
	cout << endl << endl;
	cout << BOLD UNDL BLUE "Step 2:\n" RST;
	cout << endl << endl;
}

// void	PmergeMe::sort(std::vector<uint32_t> &base)
// {
// 	(void) base;
// }

