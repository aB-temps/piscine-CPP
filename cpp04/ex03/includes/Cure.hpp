/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 17:54:59 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__CURE_HPP__
# define	__CURE_HPP__

# include	"AMateria.hpp"

# define	CURE_TYPENAME "cure"

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &copy);
		~Cure(void);

		Cure	&operator=(const Cure &assign);
		Cure	*clone(void) const;
		void	use(ICharacter &target);
		
};

#endif
