/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:28:04 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 10:58:46 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__HUMANB_HPP__
# define	__HUMANB_HPP__

# include "Weapon.hpp"

class	HumanB
{
	public:
		HumanB(std::string name);
		void			setWeapon(Weapon *weapon);
		void			attack(void) const;

	private:
		std::string		_name;
		Weapon			*_weapon;
};


#endif

