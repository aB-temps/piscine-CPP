/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/19 18:04:26 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__EASYFIND_HPP__
# define	__EASYFIND_HPP__

# include <algorithm>

template					<typename T>
typename T::const_iterator	easyfind(const T &ctn, const int v);

# include "easyfind.tpp"

#endif
