/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 16:45:26 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__DOG_HPP__
# define	__DOG_HPP__

# include "AAnimal.hpp"
# include "Brain.hpp"

class	Dog: public AAnimal
{
	public:
		Dog(void);
		Dog(const Dog &copy);
		~Dog(void);

		Dog		&operator=(const Dog &assign);

	 	void	makeSound(void) const;

	private:
		Brain	*_brain;
};

#endif
