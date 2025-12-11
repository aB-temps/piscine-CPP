/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 17:55:17 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__AMATERIA_HPP__
# define	__AMATERIA_HPP__

# include	"IMateriaSource.hpp"
# define	DEF_TYPENAME "Empty"

class	AMateria: public IMateriaSource
{
	public:
		AMateria(void);
		AMateria(const AMateria &copy);
		AMateria(std::string const &type);
		~AMateria(void);

		AMateria				&operator=(const AMateria &assign);

		std::string const		&getType(void) const;
		virtual AMateria		*clone(void) const = 0;
		virtual void			use(ICharacter &target);

	protected:
		std::string				_type;
		
};

#endif
