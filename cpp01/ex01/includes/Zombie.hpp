/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 15:50:10 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/27 16:10:49 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__ZOMBIE_HPP__
# define	__ZOMBIE_HPP__

# include <string>

# define BOLD	"\001\033[1m\002"
# define RED	"\001\033[31m\002"
# define GREEN	"\001\033[32m\002"
# define YELLOW	"\001\033[33m\002"
# define RST	"\001\033[0m\002"

class	Zombie
{
	public:
		Zombie(void);
		~Zombie(void);
		void	setName(std::string name);
		void	announce(void) const;

	private:
		std::string	_name;
};

#endif
