/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/02 14:30:06 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__AANIMAL_HPP__
# define	__AANIMAL_HPP__

# include <iostream>

# define DEF_ATYPE "AAnimal"

class	AAnimal
{
	public:
		AAnimal(void);
		AAnimal(const AAnimal &copy);
		virtual ~AAnimal(void);

		AAnimal				&operator=(const AAnimal &assign);

		const std::string	&getType(void) const;
		virtual void		makeSound(void) const = 0;

	protected:
		AAnimal(std::string type);
		std::string			_type;

};

#endif
