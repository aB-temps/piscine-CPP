/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/21 17:03:03 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__MUTANTSTACK_HPP__
# define	__MUTANTSTACK_HPP__

# include <stack>

// Class declaration ===========================================================
template	<class T>
class		MutantStack: public std::stack<T>
{
	public:
		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		MutantStack(void);
		MutantStack(const MutantStack &cpy);
		~MutantStack(void);

		MutantStack&	operator=(const MutantStack &assign);

		iterator		begin(void);
		iterator		end(void);

		const_iterator	cbegin(void) const;
		const_iterator	cend(void) const;

};

# include "MutantStack.tpp"

#endif
