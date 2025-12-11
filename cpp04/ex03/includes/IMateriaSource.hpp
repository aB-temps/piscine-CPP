/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 16:35:42 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__IMATERIASOURCE_HPP__
# define	__IMATERIASOURCE_HPP__

# include "AMateria.hpp"

class	IMateriaSource
{
	public:
		IMateriaSource(void);
		IMateriaSource(const IMateriaSource &copy);
		virtual ~IMateriaSource(void);

		IMateriaSource		&operator=(const IMateriaSource &assign);

		virtual void		learnMateria(AMateria *m) = 0;
		virtual AMateria	*createMateria(std::string const &type) = 0;

	protected:
		
};

#endif
