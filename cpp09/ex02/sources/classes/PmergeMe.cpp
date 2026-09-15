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
uint32_t	roundToNextElemSize(const uint32_t toRound, const uint32_t elemSize)
{
	if (!elemSize)
		return (toRound);

	uint32_t	reminder = toRound % elemSize;
	if (reminder == 0)
		return (toRound);
	return (toRound + elemSize - reminder);
}

void	PmergeMe::_binaryInsert(std::deque<uint32_t> &dest, std::deque<uint32_t>::const_iterator src, std::deque<uint32_t>::iterator maxI,  const uint32_t elemSize)
{
	const uint32_t	element = *(src + elemSize - 1);
	std::deque<uint32_t>::iterator minI = dest.begin() + elemSize - 1;
	std::deque<uint32_t>::iterator midI;
	while (minI <= maxI)
	{
		midI = minI + roundToNextElemSize(((maxI - minI) >> 1), elemSize);
#ifdef DEBUG
		cout << "- midI: " <<  *midI << " ==> " << element << " > " << *midI << " - " << (element > *midI ? "true" : "false") << endl;
#endif
		if (element > *midI)
			minI = midI + elemSize;
		else
			maxI = midI - elemSize;
	}
	dest.insert(minI - elemSize + 1, src, src + elemSize);
}

uint32_t	PmergeMe::_getNthJS(const uint32_t n)
{
	return ((std::pow(2, n + 1) + std::pow(-1, n)) / 3);
}

void	displayElem(std::deque<uint32_t>::iterator it, const uint32_t size)
{
	cout << BOLD "[" RST GREEN;
	for (uint32_t i = 0; i < size; ++i)
		cout << *(it + i) << (i == size - 1 ? "" : " ");
	cout << RST BOLD "] " RST;
}

void	displayElemFull(std::deque<uint32_t> &deq, const uint32_t elemSize)
{
	std::deque<uint32_t>::iterator it;

	if (!deq.size())
		cout << YELLOW "empty" << RST;
	for (it = deq.begin(); it <= deq.end() - elemSize; it += elemSize)
		displayElem(it, elemSize);
}

void	PmergeMe::_recursivePairSorting(std::deque<uint32_t> &base)
{
	static uint32_t u = 0;
#ifdef DEBUG
	cout << "-----------------\nTurn no " BLUE BOLD << u + 1 << RST ":\n";
#endif
	std::deque<uint32_t>::iterator it = base.begin();

	uint32_t groupSize = std::pow(2, ++u);
	uint32_t elemSize = groupSize >> 1;
#ifdef DEBUG
	cout << "Element of size " BOLD YELLOW << elemSize << RST " grouped by: " BOLD YELLOW <<  groupSize << RST << endl;
#endif
	for (it = base.begin(); it <= base.end() - groupSize; it += groupSize)
	{
#ifdef DEBUG
		displayElem(it, groupSize);
		cout << "Comparing: " BOLD << *(it + elemSize - 1) << RST " against " BOLD << *(it + groupSize - 1) << RST "\n";
#endif
		if (*(it + elemSize - 1) > *(it + groupSize - 1))
		{
			if (elemSize > 1)
				std::swap_ranges(it, it + elemSize, it + elemSize);
			else
				PmergeMe::_swap(*it, *(it + 1));

#ifdef DEBUG
			displayElem(it, groupSize);
			cout << BOLD RED "- SWAPPING\n" RST;
#endif
		}
	}
#ifdef DEBUG
	for (; it < base.end(); ++it)
		cout << RED << *it << " ";
	cout << RST << endl;
#endif


	if (elemSize <= base.size())
		PmergeMe::_recursivePairSorting(base);

	if (u > 0)
		PmergeMe::_unrollingInsertion(base, u);
}

std::deque<uint32_t>::iterator	determineBinInsertBound(std::deque<uint32_t> &deq, const uint32_t value)
{
	return (std::find(deq.begin(), deq.end(), value));
}

void	PmergeMe::_unrollingInsertion(std::deque<uint32_t> &base, uint32_t &depth)
{
#ifdef DEBUG
	cout	<< "==> Entering via depth: " BOLD GREEN << depth << RST "\nwith base: ";
#endif

	std::deque<uint32_t>::iterator	it = base.begin();
	// static std::deque<uint32_t>			main;
	// static std::deque<uint32_t> 		pend;

	std::deque<uint32_t>		main;
	std::deque<uint32_t> 		pend;
	std::deque<uint32_t>		rest;

	uint32_t groupSize = std::pow(2, depth);
	uint32_t elemSize = groupSize >> 1;


	for (; it <= base.end() - elemSize; it += elemSize)
	{
#ifdef DEBUG
		displayElem(it, elemSize);
#endif
	}
	for (; it < base.end(); ++it)
	{
		rest.push_back(*it);
#ifdef DEBUG
		cout << RED << *it << " ";
#endif
	}
#ifdef DEBUG
	cout << "\n"RST;
#endif

	// adding {b1, a1} to main
	it = base.begin();
	main.insert(main.begin(), it, it + groupSize);

	// adding other a's to main
	for (it = base.begin() + groupSize; it <= base.end() - groupSize; it += groupSize)
		main.insert(main.end(), it + elemSize, it + groupSize);
	// adding other b's to pend
	for (it = base.begin() + groupSize; it <= base.end() - elemSize; it += groupSize)
		pend.insert(pend.end(), it, it + elemSize);



#ifdef DEBUG
	cout << "Main: ";
	displayElemFull(main, elemSize);
	cout << "\nPend: ";
	displayElemFull(pend, elemSize);
	cout << endl;
#endif

	if (pend.size())
	{
		uint32_t	jsCounter = 2;

		uint32_t	jsVal = PmergeMe::_getNthJS(jsCounter);
		uint32_t	lastJsVal = PmergeMe::_getNthJS(jsCounter - 1) ;

#ifdef DEBUG
		uint32_t	elemQty = pend.size() / elemSize;
		cout << "Elem Quantity: " << elemQty;
#endif
		uint32_t	insertionQty = jsVal - lastJsVal;
		uint32_t	insertI = jsVal;

		uint32_t	inserted = 0;

		while (inserted < pend.size() / elemSize)
		{
#ifdef DEBUG
			cout << BOLD "\njsVal: " BLUE << jsVal << RST << endl;
			cout << BOLD "lastJsVal: " BLUE << lastJsVal << RST << endl;
			cout << BOLD "Trying to insert " BLUE << insertionQty << " new elements\n" RST << endl;
#endif

			while (insertI > lastJsVal)
			{
#ifdef DEBUG
				cout << BOLD "InsertI: " BLUE << insertI << RST << endl;
#endif

				// defining which element to insert
				while (insertionQty > (pend.size() / elemSize) - inserted)
				{
					--insertI;
					--insertionQty;
#ifdef DEBUG
					cout << RED "Not enough elements to insert according to JS sequence, skipping." RST << endl;
					cout << BOLD "Trying to insert " BLUE << insertionQty << " new elements while remains " << (pend.size() / elemSize) - inserted << " elements to insert." RST << endl;
					cout << BOLD "InsertI: " BLUE << insertI << RST << endl << endl;
#endif
				}
#ifdef DEBUG
				cout << GREEN "Inserting element no " BOLD << insertI - 1 << RST ": [";
#endif
				const uint32_t	offset = elemSize * (insertI - 2);
#ifdef DEBUG
				for (it = pend.begin() + offset; it < pend.begin() + offset + elemSize; ++it)
					cout << *it << " ";
				cout << "\b]" << endl;
#endif
				it = pend.begin() + offset;

				// defining maxBound
				std::deque<uint32_t>::iterator	maxBoundIt = main.end() - 1;
				const uint32_t	winnerPos = (((elemSize << 1) * insertI) - 1);
				if (winnerPos < base.size())
				{
					const uint32_t	winnerVal = base[winnerPos];
#ifdef DEBUG
					cout << "Winner Value: " << winnerVal << " for pair no " BOLD YELLOW << insertI << RST << endl;
#endif
					maxBoundIt = determineBinInsertBound(main, winnerVal);
					if (maxBoundIt == main.end())
						maxBoundIt = main.end() - 1;
#ifdef DEBUG
					cout << "maxBoundIt: " << *maxBoundIt << endl;
#endif
				}
#ifdef DEBUG
				else
					cout << RED "not paired (odd)" RST << endl;
#endif

				// insert into main, erasing into pend
				PmergeMe::_binaryInsert(main, it, maxBoundIt, elemSize);
				// pend.erase(it, it + elemSize);
				--insertionQty;
				--insertI;
				++inserted;

#ifdef DEBUG
				// display main & pend after insert
				cout << "Main: ";
				displayElemFull(main, elemSize);
				cout << "\nPend: ";
				displayElemFull(pend, elemSize);
				cout << endl << endl;
#endif
			}
			lastJsVal = jsVal;
			jsVal = PmergeMe::_getNthJS(++jsCounter);
			insertionQty = jsVal - lastJsVal;
			insertI = jsVal;
		}

	}
	main.insert(main.end(), rest.begin(), rest.end());
	base = main;
	--depth;
}

void	PmergeMe::sort(std::deque<uint32_t> &base)
{
	PmergeMe::_recursivePairSorting(base);
}

// void	PmergeMe::sort(std::vector<uint32_t> &base)
// {
// 	(void) base;
// }

