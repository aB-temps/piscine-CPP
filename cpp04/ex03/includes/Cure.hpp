/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 14:30:06 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__CURE_HPP__
# define	__CURE_HPP__

# include <iostream>

class	Cure: public AMateria
{
	public:
		Cure(void);
		Cure(const Cure &copy);
		~Cure(void);

		Cure					&operator=(const Cure &assign);

	protected:
		
};

#endif
