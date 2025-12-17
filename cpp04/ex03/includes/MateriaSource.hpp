/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/10 16:35:42 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__MATERIASOURCE_HPP__
# define	__MATERIASOURCE_HPP__

# include	"IMateriaSource.hpp"
# include	"AMateria.hpp"

# define	KNOWLEDGE_SIZE 4

class	MateriaSource: public IMateriaSource
{
	public:
		MateriaSource(void);
		MateriaSource(const MateriaSource &copy);
		virtual ~MateriaSource(void);

		MateriaSource	&operator=(const MateriaSource &assign);
		void			learnMateria(AMateria *m);
		AMateria		*createMateria(std::string const &type);

	private:
		AMateria		*_knowledge[KNOWLEDGE_SIZE];
		int				_free_space;

};

#endif
