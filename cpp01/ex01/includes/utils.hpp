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

# include <iostream>
# include "Zombie.hpp"

# define BOLD	"\001\033[1m\002"
# define RED	"\001\033[31m\002"
# define GREEN	"\001\033[32m\002"
# define YELLOW	"\001\033[33m\002"
# define RST	"\001\033[0m\002"

# define DEFAULT_ZOMBIE_NAME	"Coco"
# define DEFAULT_HORDE_SIZE		9
# define MIN_HORDE_SIZE			2

void	string_to_int(int &value, std::string str);
Zombie	*zombieHorde(int N, std::string name);

#endif
