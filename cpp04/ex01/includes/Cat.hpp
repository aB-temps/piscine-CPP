/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 16:45:11 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__CAT_HPP__
# define	__CAT_HPP__

# include "Animal.hpp"
# include "Brain.hpp"

class	Cat: public Animal
{
	public:
		Cat(void);
		Cat(const Cat &copy);
		~Cat(void);

		Cat		&operator=(const Cat &assign);

		void	makeSound(void) const;
	
	private:
		Brain	*_brain;
};

#endif
