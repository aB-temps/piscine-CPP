/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/12 18:13:03 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/12 18:14:56 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__MIN_TPP__
# define	__MIN_TPP__

template <typename T>
const T	&min(const T &a, const T &b)
{
	return (a < b ? a : b);
}

# endif
