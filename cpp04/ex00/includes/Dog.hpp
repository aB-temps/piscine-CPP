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

# include "Animal.hpp"

class	Dog: Animal
{
	public:
		Dog(void);
		Dog(std::string type);
		Dog(const Dog &copy);
		~Dog(void);

		Dog			&operator=(const Dog &assign);

	 	void	makeSound(void);
};

#endif
