/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:09:59 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/12 18:14:45 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__SWAP_TPP__
# define	__SWAP_TPP__

template <typename T>
void	swap(T &a,T &b)
{
	T	tmp;

	tmp = a;
	a = b;
	b = tmp;
}

# endif
