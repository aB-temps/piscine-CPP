/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.tpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/21 17:03:53 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/21 17:04:35 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__MUTANTSTACK_TPP__
# define	__MUTANTSTACK_TPP__

// Construction ----------------------------------------------------------------
template	<typename T>
MutantStack<T>::MutantStack(void): std::stack<T>() {}

template	<typename T>
MutantStack<T>::MutantStack(const MutantStack &cpy): std::stack<T>(cpy) {}

template	<typename T>
MutantStack<T>::~MutantStack(void) {}

// Ops overloading -------------------------------------------------------------
template	<typename T>
MutantStack<T>	&MutantStack<T>::operator=(const MutantStack<T> &assign)
{
	if (this != &assign)
	{
		this->std::stack<T>::operator=(assign);
	}
	return (*this);
}

// Member functions ------------------------------------------------------------
template	<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::begin(void)
{
	return (this->std::stack<T>::c.begin());
}

template	<typename T>
typename MutantStack<T>::iterator	MutantStack<T>::end(void)
{
	return (this->std::stack<T>::c.end());
}

template	<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cbegin(void) const
{
	return (this->std::stack<T>::c.cbegin());
}

template	<typename T>
typename MutantStack<T>::const_iterator	MutantStack<T>::cend(void) const
{
	return (this->std::stack<T>::c.cend());
}

#endif
