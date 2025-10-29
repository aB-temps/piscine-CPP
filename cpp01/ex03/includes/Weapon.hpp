/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 10:28:08 by abetemps          #+#    #+#             */
/*   Updated: 2025/10/29 11:02:18 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#ifndef		__WEAPON_HPP__
# define	__WEAPON_HPP__

class	Weapon
{
	public:
		const std::string	&getType(void) const;
		void				setType(std::string type); 

	private:
		std::string			_type;
}

#endif
