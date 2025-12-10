/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 14:30:06 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__CHARACTER_HPP__
# define	__CHARACTER_HPP__

# include	<iostream>

# define	INV_SIZE 4

class	Character
{
	public:
		Character(void);
		Character(const Character &copy);
		virtual ~Character(void);

		Character				&operator=(const Character &assign);

		virtual std::string const	&getName(void) const = 0;
		virtual void				equip(AMateria *m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, Character &target) = 0;

	private:
		AMateria					_inventory[INV_SIZE];
		
};

#endif
