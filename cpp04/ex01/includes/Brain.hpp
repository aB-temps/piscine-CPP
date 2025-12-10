/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 21:44:57 by abetemps          #+#    #+#             */
/*   Updated: 2025/12/09 21:47:06 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__BRAIN_HPP__
# define	__BRAIN_HPP__

# include 	<iostream>

class Brain
{
	public:
		Brain(void);
		Brain(const Brain &copy);
		~Brain(void);

		Brain			&operator=(const Brain &assign);

	private:
		std::string		_ideas[100];

};

#endif
