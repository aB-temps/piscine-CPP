/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/09 19:23:53 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__WRONGANIMAL_HPP__
# define	__WRONGANIMAL_HPP__

# include <iostream>

# define DEF_WTYPE "WrongAnimal"

class	WrongAnimal
{
	public:
		WrongAnimal(void);
		WrongAnimal(const WrongAnimal &copy);
		virtual ~WrongAnimal(void);

		WrongAnimal				&operator=(const WrongAnimal &assign);

		const std::string	&getType(void) const;
		void		makeSound(void) const;

	protected:
		WrongAnimal(std::string type);
		std::string			_type;

};

#endif
