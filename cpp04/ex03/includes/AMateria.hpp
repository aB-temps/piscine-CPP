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

# include	<iostream>
# include	"ICharacter.hpp"

# define	DEF_TYPENAME "Nothing"

class ICharacter;

class	AMateria
{
	public:
		AMateria(void);
		AMateria(const AMateria &copy);
		AMateria(std::string const &type);
		virtual ~AMateria(void);

		AMateria				&operator=(const AMateria &assign);

		std::string const		&getType(void) const;
		const bool				&getLearnedState(void) const;
		void					setLearnedState(const bool &state);
		virtual AMateria		*clone(void) const = 0;
		virtual void			use(ICharacter &target);

	protected:
		std::string				_type;
		bool					_learned;

};

#endif
