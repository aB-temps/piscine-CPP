/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 17:54:43 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ICE_HPP__
# define	__ICE_HPP__

# include	"AMateria.hpp"

# define	ICE_TYPENAME "ice"

class	Ice: public AMateria
{
	public:
		Ice(void);
		Ice(const Ice &copy);
		~Ice(void);

		Ice					&operator=(const Ice &assign);

	protected:
		
};

#endif
