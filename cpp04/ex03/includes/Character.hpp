/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 17:50:55 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__CHARACTER_HPP__
# define	__CHARACTER_HPP__

# include	"ICharacter.hpp"

class	Character: public ICharacter
{
	public:
		Character(void);
		Character(const Character &copy);
		virtual ~Character(void);

		Character				&operator=(const Character &assign);
		
};

#endif
