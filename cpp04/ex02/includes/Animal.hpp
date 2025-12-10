/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 14:30:06 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ANIMAL_HPP__
# define	__ANIMAL_HPP__

# include <iostream>

# define DEF_TYPE "Animal"
# define DEF_ARRAY_SIZE 4

class	Animal
{
	public:
		Animal(void);
		Animal(const Animal &copy);
		virtual ~Animal(void);

		Animal				&operator=(const Animal &assign);

		const std::string	&getType(void) const;
		virtual void		makeSound(void) const;

	protected:
		Animal(std::string type);
		std::string			_type;

};

#endif
