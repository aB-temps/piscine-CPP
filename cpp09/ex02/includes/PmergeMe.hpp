/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/12 15:08:16 by abetemps          #+#    #+#             */
/*   Updated: 2026/08/12 19:38:26 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__PMERGEME_HPP__
# define	__PMERGEME_HPP__

# include <stdint.h>
# include <iostream>
# include <deque>
# include <vector>
# include "errors.hpp"

class	PmergeMe
{
	public:
		template	<typename T>
		static T			buildCtn(const int ac, const char * const * av);
		static void			sort(std::deque<uint32_t> &base);
		// static void			sort(std::vector<uint32_t> &base);

	private:
		PmergeMe(void);
		PmergeMe(const PmergeMe &cpy);
		~PmergeMe(void);
		PmergeMe	&operator=(const PmergeMe &assign);

		static bool	_isOnlyNum(const std::string &str);
};

std::ostream	&operator<<(std::ostream &out, const std::vector<uint32_t> &vec);
std::ostream	&operator<<(std::ostream &out, const std::deque<uint32_t> &deq);

# include "PmergeMe.tpp"

#endif
