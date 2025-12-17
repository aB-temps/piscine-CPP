/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 17:53:50 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ICHARACTER_HPP__
# define	__ICHARACTER_HPP__

# include	"AMateria.hpp"


class	ICharacter
{
	public:
		ICharacter(void);
		ICharacter(const ICharacter &copy);
		virtual ~ICharacter(void);

		ICharacter					&operator=(const ICharacter &assign);

		virtual std::string const	&getName(void) const = 0;
		virtual void				equip(AMateria *m) = 0;
		virtual void				unequip(int idx) = 0;
		virtual void				use(int idx, ICharacter &target) = 0;
};

#endif
