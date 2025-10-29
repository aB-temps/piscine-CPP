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

# include <iostream>

class	Zombie
{
	public:
		Zombie(void);
		Zombie(std::string name);
		~Zombie(void);
		void	announce(void) const;

	private:
		std::string	_name;
};

#endif
