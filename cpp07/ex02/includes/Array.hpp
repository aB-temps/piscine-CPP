/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abetemps <abetemps@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 16:57:21 by abetemps          #+#    #+#             */
/*   Updated: 2026/03/17 16:57:45 by abetemps         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		__ARRAY_HPP__
# define	__ARRAY_HPP__

# include <iostream>

template	<typename Type>
class		Array
{
	public:
		Array(void);
		Array(const unsigned int &n);
		Array(const Array &copy);
		~Array(void);

		Array<Type>			&operator=(const Array<Type> &assign);
		Type 				&operator[](const unsigned int &i);
		const Type 			&operator[](const unsigned int &i) const;

		unsigned int		size(void) const;

	private:
		Type				*_array;
		unsigned int		_size;
};

template		<typename Type>
std::ostream	&operator<<(std::ostream &out, Array<Type> &array);

# include "Array.tpp"

#endif
