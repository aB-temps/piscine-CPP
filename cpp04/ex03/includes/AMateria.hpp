/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 14:30:06 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__AMATERIA_HPP__
# define	__AMATERIA_HPP__

# include <iostream>

class	AMateria
{
	public:
		AMateria(void);
		AMateria(const AMateria &copy);
		virtual ~AMateria(void);

		AMateria				&operator=(const AMateria &assign);

	protected:
		
};

#endif
