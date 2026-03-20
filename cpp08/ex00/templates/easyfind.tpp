/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 16:29:22 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/19 17:42:33 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__EASYFIND_TPP__
# define	__EASYFIND_TPP__

template 					<typename C>
typename C::const_iterator	easyfind(const C &ctn, const int &v)
{
	typename C::const_iterator	i;
	for (i = ctn.begin(); i != ctn.end(); ++i)	
	{
		if (*i == v)
			return (i);
	}
	return (i);
}

#endif
