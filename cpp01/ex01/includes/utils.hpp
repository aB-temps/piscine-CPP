/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:32:53 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/27 19:34:04 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__UTILS_HPP__
# define	__UTILS_HPP__

# include <string>
# include "Zombie.hpp"

# define DEFAULT_ZOMBIE_NAME		"Kunfandi"	
# define DEFAULT_ZOMBIE_QUANTITY	9

int		string_to_int(int value&, std::string str);

Zombie	*zombieHorde(int N, std::string name);

#endif
