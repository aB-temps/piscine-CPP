/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   factory.tpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/10 13:36:58 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/10 14:25:17 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__FACTORY_TPP__
# define 	__FACTORY_TPP__

# include "Base.hpp"

typedef	Base *(*t_builder)(void);

template <typename T>
Base *	newBase(void)
{
	return (new T());
}

#endif
